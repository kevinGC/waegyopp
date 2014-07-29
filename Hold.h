#ifndef HOLD_H
#define HOLD_H

#include "Order.h"
#include <string>
#include <memory>


class Hold : public Order {
public:
	Hold(const std::string& line);
	~Hold() {}

private:
	bool valid;
	std::shared_ptr<Terr> terr;

};


#endif // HOLD_H
