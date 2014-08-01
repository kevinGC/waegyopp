#ifndef JSON_UTIL_H
#define JSON_UTIL_H

#include "json/json/json.h"
#include <string>
#include <memory>
#include <map>


// TODO comments...

Json::Value get_val(const std::string& key, const Json::Value& root);
void set_terrs(const Json::Value& loc,
	const Json::Value& locs,
	std::map<std::string,std::shared_ptr<Terr>>& terrs);

#endif // JSON_UTIL_H
