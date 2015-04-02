#include <iostream>
#include <memory>

#include "MyGameApp.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "Hello World" << endl;
	auto game = make_unique<MyGameApp>();
	if (!game->init(argc,argv))
	{
		return -1;
	}

	while (game->run());

	return 0;
}