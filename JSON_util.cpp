#include "JSON_util.h"
#include "Sea.h"
#include "Coastal.h"
#include "Landlock.h"
#include <stdexcept>
using std::string;
using std::map;
using std::shared_ptr;
using std::invalid_argument;

Json::Value get_val(const string& key, const Json::Value& root)
{
	Json::Value val = root[key];
	if(!val)
		throw invalid_argument("no '" + key + "' field");
	return val;
}

// TODO add "landlock" to default_world.json
// TODO coastals need to specify coast nums of each adj coast
// TODO all Coastals need coast fields. Adjacent refers only to adjacent Landlocks
void set_terrs(const Json::Value& loc,
	const Json::Value& locs,
	map<string,shared_ptr<Terr>>& terrs)
{
	string terrain = loc["terrain"].asString();
	if(terrain == "sea") {
		new Sea(loc, locs, terrs);
	} else if(terrain == "landlock") {
		new Landlock(loc, locs, terrs);
	} else if(terrain == "coastal") {
		new Coastal(loc, locs, terrs);
	} else {
		throw invalid_argument("unrecognized Terr subtype");
	}
}
