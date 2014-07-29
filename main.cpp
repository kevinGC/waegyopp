#include "CLI_controller.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Hello, 외교" << endl;
	CLI_controller controller = CLI_controller();
	controller.run();

	return 0;
}
