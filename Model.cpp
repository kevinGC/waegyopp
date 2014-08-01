#include "Model.h"
#include "JSON_util.h"
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <iostream> // TODO delete
using std::cout; using std::endl; // TODO delete
using std::vector;
using std::map;
using std::string;
using std::shared_ptr;
using std::ifstream;
using std::istreambuf_iterator;
using std::invalid_argument;


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
	// get string
	ifstream ifs{filename};
	string file_contents(istreambuf_iterator<char>{ifs}, istreambuf_iterator<char>());
	// parse JSON
	Json::Value root;
	Json::Reader reader;
	if(!reader.parse(file_contents, root))
		throw invalid_argument("invalid JSON in file " + filename);
	const Json::Value locations = get_val("locations", root);
	const Json::Value nations = get_val("nations", root);

	set_terrs(locations[0], locations, terrs);

	// create nations
}
