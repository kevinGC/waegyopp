#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <memory>
class Terr;


class Order {
public:
	virtual ~Order() {}
	bool is_valid() const
		{ return valid; }

protected:
	bool valid;
	std::shared_ptr<Terr> origin;

	Order() : valid{true} {}

};


#endif // ORDER_H
