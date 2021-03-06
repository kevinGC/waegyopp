#ifndef REG_TERR_H
#define REG_TERR_H

#include "Terr.h"

class Reg_terr : public Terr {
public:
	Reg_terr(const Json::Value& loc,
		const Json::Value locs,
		std::map<std::string, std::shared_ptr<Terr>>& terrs)
		: Terr{loc, locs, terrs}
		{}

	//TODO
	bool can_move_to() const override { return true; }
};


#endif // REG_TERR_H
