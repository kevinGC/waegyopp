#include "Terr.h"
#include "JSON_util.h"
#include <algorithm>
#include <cassert>
using std::find_if;
using std::map;
using std::string;
using std::shared_ptr;


Terr::Terr(const Json::Value& loc,
	const Json::Value locs,
	map<string, shared_ptr<Terr>>& terrs)
	: short_name{get_val("short_name", loc).asString()}
	, display_name{get_val("display_name", loc).asString()}
	, has_center{get_val("has_center", loc).asBool()}
	, adjacent{}
	, piece{}
{
	terrs[short_name] = shared_ptr<Terr>(this); // sketchy...
	assert(terrs.find(short_name) != terrs.end());
	for(const auto& adj_val : get_val("adjacent", loc)) {
		string adj_name = adj_val.asString();
		if(terrs.find(adj_name) == terrs.end()) {
			const auto it = find_if(locs.begin(), locs.end(),
				[&adj_name](const Json::Value& t) {
					return get_val("short_name", t) == adj_name;
				});
			assert(it != locs.end());
			set_terrs(*it, locs, terrs);
			assert(terrs.find(adj_name) != terrs.end()); // TODO NDEBUG
			adjacent.push_back(terrs[adj_name]);
		}
	}
}
