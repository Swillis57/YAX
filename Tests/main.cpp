//For testing purposes

#include <iostream>
#define CATCH_CONFIG_RUNNER
#include "catch.h"

int main(int argc, char* const argv[])
{
	int res = Catch::Session().run(argc, argv);
	std::cin.get();
	return res;
}
