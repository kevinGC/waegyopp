#ifndef MODEL_H
#define MODEL_H

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

};

#endif // MODEL_H
