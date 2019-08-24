#include <iostream>
#include <memory>
#include "Resource.h"

auto doSomething()
{
	return std::make_unique<Resource>(5);
}

int main()
{
	doSomething();
	return 0;
}
