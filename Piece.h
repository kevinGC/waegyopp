#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <memory>
class Sea;
class Landlock;
class Coastal;


class Piece {
public:
	virtual const std::string& get_type_string() const = 0;
	virtual bool can_occupy(std::shared_ptr<const Sea>& sea) const = 0;
	virtual bool can_occupy(std::shared_ptr<const Landlock>& landlock) const = 0;
	virtual bool can_occupy(std::shared_ptr<const Coastal>& coastal) const = 0;

private:


};

class Army : Piece {
public:
	virtual const std::string& get_type_string() const override
	{
		static const std::string type_string = std::string("A");
		return type_string;
	}

	bool can_occupy(std::shared_ptr<const Sea>& sea) const override
		{ return false; }

	bool can_occupy(std::shared_ptr<const Landlock>& landlock) const override
		{ return true; }

	bool can_occupy(std::shared_ptr<const Coastal>& coastal) const override
		{ return true; }

private:


};

class Fleet : Piece {
public:
	virtual const std::string& get_type_string() const override
	{
		static const std::string type_string = std::string("F");
		return type_string;
	}

	bool can_occupy(std::shared_ptr<const Sea>& sea) const override
		{ return true; }

	bool can_occupy(std::shared_ptr<const Landlock>& landlock) const override
		{ return false; }

	bool can_occupy(std::shared_ptr<const Coastal>& coastal) const override
		{ return true; }

private:


};


#endif // PIECE_H
