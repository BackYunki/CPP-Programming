#include <iostream>
#include <memory>
#include "Resource.h"
int main()
{
	Resource* res = new Resource(3);
	res->setAll(1);

	{
		std::shared_ptr<Resource> ptr1(res);

		ptr1->print();

		{
			std::shared_ptr<Resource> ptr2(ptr1);
			ptr2->setAll(3);
			ptr2->print();

			std::cout << "Going out of inner block.\n";
		}

		ptr1->print();
		std::cout << "Going out of outer block.\n";
	}

	return 0;
}

