#include "Model.h"
using std::string;
using std::shared_ptr;


Model& Model::get()
{
	static Model model("default_world.json");
	return model;
}

std::shared_ptr<Terr> Model::get_terr(const string& terr_name)
{
	auto it = terrs.find(terr_name);
	if(it == terrs.end())
		return shared_ptr<Terr>{};
	return it->second;
}

Model::Model(const string& filename) : terrs{}
{
	// TODO oh god JSON again
}
