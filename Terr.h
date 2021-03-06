#ifndef TERR_H
#define TERR_H

#include "json/json/json.h"
#include "Piece.h"
#include <memory>
#include <string>
#include <vector>
#include <map>


class Terr : public std::enable_shared_from_this<Terr> {
public:
	Terr(const Json::Value& loc,
		const Json::Value locs,
		std::map<std::string, std::shared_ptr<Terr>>& terrs);

	bool has_piece()
		{ return piece.use_count(); }

	std::shared_ptr<Piece> get_piece()
		{ return piece; }

	// double dispatch
	// TODO because of shared_from_this, does this not work? need to check
	virtual bool can_be_occupied_by(std::shared_ptr<const Piece>& piece) const = 0;

private:
	std::string short_name;
	std::string display_name;
	bool has_center;
	std::vector<std::shared_ptr<Terr>> adjacent;
	std::shared_ptr<Piece> piece;

};


#endif // TERR_H
