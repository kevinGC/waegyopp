#include "Model.h"
#include "JSON_util.h"
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <typeinfo>
#include <iostream> // TODO delete
using std::cout; using std::endl; // TODO delete
using std::vector;
using std::map;
using std::string;
using std::shared_ptr;
using std::ifstream;
using std::istreambuf_iterator;
using std::invalid_argument;


Model::Model(const string& filename)
	: terrs{}
	, seas{}
	, coastals{}
	, landlocks{}
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
	// TODO set up other 3 maps with typeid
	for(auto terr : terrs) {
		switch(typeid(terr) == typeid(terrs::element_type)) {
			default: break;
		}
	}

	// create nations
}
