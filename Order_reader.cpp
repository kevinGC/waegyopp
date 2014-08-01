#include "Order_reader.h"
#include "Order.h"
#include "Hold.h"
#include <memory>
#include <iostream>
#include <string>
#include <stdexcept>
using std::string;
using std::unique_ptr;
using std::cin; using std::getline;
// using std::cout; using std::endl; // TODO remove
using std::invalid_argument; // TODO do I really want this exception everywhere?


// returs false if 'end' is read. Returns true is leaves cin unaltered if
// anything else is read
bool is_another_order()
{
	if(cin.peek() == 'e')
		return false;
	return true;
}

unique_ptr<Order> get_next_order()
{
	string line;
	getline(cin, line);
	// cout << "Next order line is: " << line << endl;

	auto hold = unique_ptr<Order>(new Hold(line));
	if(hold->is_valid()) {
		return unique_ptr<Order>(new Hold(line));
	} else {
		throw invalid_argument("order invalid: " + line);
	}
}
