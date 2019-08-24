#include <iostream>
#include "Resource.h"
#include "AutoPtr.h"
using namespace std;

void doSomething()
{
	AutoPtr<Resource> ptr(new Resource);
}

int main()
{
	doSomething();

	return 0;
}