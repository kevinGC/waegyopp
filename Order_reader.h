#ifndef ORDER_READER_H
#define ORDER_READER_H

#include "Order.h"
#include <memory>


bool is_another_order();
std::unique_ptr<Order> get_next_order();


#endif // ORDER_READER_H
