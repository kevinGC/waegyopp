#ifndef MODEL_H
#define MODEL_H

#include "json/json/json.h"
#include <string>
#include <memory>
#include <map>
class Terr;

class Model {
public:
	static Model& get();
	std::shared_ptr<Terr> get_terr(const std::string& terr_name);

private:
	std::map<std::string, std::shared_ptr<Terr>> terrs;

	Model(const std::string& filename);
	void create_terr(const Json::Value& val);

};

#endif // MODEL_H
