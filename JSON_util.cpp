#include "JSON_util.h"
#include "Reg_terr.h"
#include "Two_coast_terr.h"
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

// TODO need to check for "coastal" isNull(), or is "single" or "double" on
// land territories
void set_terrs(const Json::Value& loc,
	const Json::Value& locs,
	map<string,shared_ptr<Terr>>& terrs)
{
	if(loc["terrain"].asString() == "sea") {
		new Sea(loc, locs, terrs);
	} else if(loc["coastal"].isNull()) {
		new Landlock(loc, locs, terrs);
	} else if(loc["coastal"].asString() == "single") {
		new SingleCoast(loc, locs, terrs);
	} else if(loc["coastal"].asString() == "double") {
		new DoubleCoast(loc, locs, terrs);
	} else {
		throw invalid_argument("unrecognized Terr subtype");
	}
}
