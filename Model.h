#ifndef MODEL_H
#define MODEL_H

#include "json/json/json.h"
#include <string>
#include <memory>
#include <map>
class Terr;
class Sea;
class Coastal;
class Landlock;

class Model {
public:
	static Model& get()
	{
		static Model model("default_world.json");
		return model;
	}

	std::shared_ptr<Terr> get_terr(const std::string& terr_name)
		{ return terrs.at(terr_name); }

	std::shared_ptr<Sea> get_sea(const std::string& sea_name)
		{ return seas.at(sea_name); }

	std::shared_ptr<Coastal> get_coastal(const std::string& coastal_name)
		{ return coastals.at(coastal_name); }

	std::shared_ptr<Landlock> get_landlock(const std::string& landlock_name)
		{ return landlocks.at(landlock_name); }

private:
	std::map<std::string, std::shared_ptr<Terr>> terrs;
	std::map<std::string, std::shared_ptr<Sea>> seas;
	std::map<std::string, std::shared_ptr<Coastal>> coastals;
	std::map<std::string, std::shared_ptr<Landlock>> landlocks;

	Model(const std::string& filename);

};

#endif // MODEL_H
