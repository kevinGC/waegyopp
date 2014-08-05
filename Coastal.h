#ifndef COASTAL_H
#define COASTAL_H

#include "Terr.h"
#include <vector>
#include <memory>


class Coastal : public Terr {
public:
	Coastal(const Json::Value& loc,
		const Json::Value locs,
		std::map<std::string, std::shared_ptr<Terr>>& terrs);

	bool can_be_occupied_by(std::shared_ptr<const Piece>& piece) const override;

private:
	class Coast {
	public:
		Coast(const Json::Value& coast_data);

	private:
		std::shared_ptr<const Coast> adj1;
		std::shared_ptr<const Coast> adj2;
		std::vector<std::shared_ptr<const Terr>> seas;

	};

	std::vector<Coast> coasts;

};


#endif // COASTAL_H
