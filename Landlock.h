#ifndef LANDLOCK_H
#define LANDLOCK_H

#include "Terr.h"


class Landlock : public Terr {
public:
	Landlock(const Json::Value& loc,
		const Json::Value locs,
		std::map<std::string, std::shared_ptr<Terr>>& terrs)
	: Terr{loc, locs, terrs}
	{}

	bool can_be_occupied_by(std::shared_ptr<const Piece>& piece) const override;

};


#endif // LANDLOCK_H
