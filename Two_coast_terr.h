#ifndef TWO_COAST_TERR_H
#define TWO_COAST_TERR_H

#include "Terr.h"

class Two_coast_terr : public Terr {
public:
	Two_coast_terr(const Json::Value& loc,
		const Json::Value locs,
		std::map<std::string, std::shared_ptr<Terr>>& terrs)
		: Terr{loc, locs, terrs}
		{}

	//TODO
	bool can_move_to() const override { return true; }
};


#endif // TWO_COAST_TERR_H
