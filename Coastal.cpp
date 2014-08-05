#include "Coastal.h"
#include "JSON_util.h"
#include "Model.h"
#include <memory>
#include <stdexcept>
using std::shared_ptr; using std::static_pointer_cast;
using std::map;
using std::string;
using std::invalid_argument;


static const char* const coasts_key = "coasts";

static get_coast(const string& key, const Json::Value& coast_data);

Coastal::Coastal(const Json::Value& loc,
		const Json::Value locs,
		map<string, shared_ptr<Terr>>& terrs)
	: Terr{loc, locs, terrs}
	, coasts{}
{
	if(loc[coasts_key].isNull())
		throw invalid_argument("no 'coasts' field in Coastal json");
	for(const Json::Value& val : get_val(coasts_key, loc)) {
		coasts.emplace_back(val);
	}
}

bool Coastal::can_be_occupied_by(shared_ptr<const Piece>& piece) const
{
	auto self = static_pointer_cast<const Coastal>(shared_from_this());
	return piece->can_occupy(self);
}

Coastal::Coast::Coast(const Json::Value& coast_data)
	: adj1{get_coast("adj1", coast_data)}
	, adj2{get_coast("adj2", coast_data)}
	, seas{}
{
	// seas
	for(const Json::Value& val : get_val("seas", coast_data)) {
		// TODO make these Seas, not Terrs! Need to add funcs to Model
		shared_ptr<const Terr> terr = Model::get().get_terr(val.asString());
		seas.push_back(terr);
	}
}

static get_coast(const string& key, const Json::Value& coast_data)
{
	const Json::Value& val = get_val(key, coast_data);
	if(val.isString()) { // if terr name only, default coast 0
		return Model::get().get_coastal(val.asString())->get_coast(0);
	} else if(val.isObject()) { // of form { "terr": <string>, "coast": <int> }
		const string& terr_name = val["terr"].asString();
		int coast_num = val["coast"].asInt();
		return Model::get().get_coastal(terr_name)->get_coast(coast_num);
	}
}
