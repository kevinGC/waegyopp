#include "Hold.h"
#include "Model.h"
#include "Terr.h"
#include "Piece.h"
#include <regex>
#include <iostream>
#include <stdexcept>
using std::cout; using std::endl;
using std::regex; using std::regex_match; using std::smatch;
using std::invalid_argument;


Hold::Hold(const std::string& line)
	: Order{}
{
	smatch matches;
	regex hold {"hold (F|A) (...)"};
	valid = regex_match(line, matches, hold);
	if(!valid)
		return;
	origin = Model::get().get_terr(matches[1]);
	if(!origin)
		throw invalid_argument("invalid territory name:" + line);
	auto piece = origin->get_piece();
	if(!piece)
		throw invalid_argument("not piece at territory:" + line);
	if(piece->get_type_string() != matches[0])
		throw invalid_argument("invalid piece type does not match:" + line);
}
