#ifndef TERR_H
#define TERR_H

#include <memory>
class Piece;


class Terr {
public:
	std::weak_ptr<Piece> get_piece()
		{ return piece; }

	virtual bool can_move_to() = 0;

private:
	std::shared_ptr<Piece> piece;

};


#endif // TERR_H
