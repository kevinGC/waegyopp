#ifndef SEA_H
#define SEA_H

#include "Terr.h"


class Sea : public Terr {
public:
	Sea(const Json::Value& loc,
		const Json::Value locs,
		std::map<std::string, std::shared_ptr<Terr>>& terrs)
	: Terr{loc, locs, terrs}
	{}

	bool can_be_occupied_by(std::shared_ptr<const Piece>& piece) const override;

};


#endif // SEA_H
