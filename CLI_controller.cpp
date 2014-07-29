#include "CLI_controller.h"
#include "Model.h"
#include "Order.h"
#include "Order_reader.h"
#include <iostream>
#include <list> // TODO forward_list?
#include <memory>
#include <exception>
using std::cout; using std::endl;
using std::list;
using std::unique_ptr;
using std::exception;


CLI_controller::CLI_controller()
{

}

void CLI_controller::run()
{
		// Model model = Model("default_world.json");
		list<unique_ptr<Order>> orders = list<unique_ptr<Order>>();

		// main input and game loop
		while(true) {
			try {
				while(is_another_order()) {
					orders.push_back(get_next_order()); // get order
				}
			} catch(exception& e) {
				cout << "Unknown error caught:" << endl;
				cout << e.what() << endl;
			}
			// process orders
		}
		// game is won or exited
}
