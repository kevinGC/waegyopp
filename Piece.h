#ifndef PIECE_H
#define PIECE_H

#include <string>
using std::string;


class Piece {
public:
	virtual const string& get_type_string() const = 0;

private:


};

class Army : Piece {
public:
	virtual const string& get_type_string() const override {
		static const string type_string = string("A");
		return type_string;
	}

private:


};

class Fleet : Piece {
public:
	virtual const string& get_type_string() const override {
		static const string type_string = string("F");
		return type_string;
	}

private:


};


#endif // PIECE_H
