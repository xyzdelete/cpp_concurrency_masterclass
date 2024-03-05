#include <thread>
#include <iostream>

void functionA()
{
	std::cout << "functionA" << std::endl;

	std::thread threadC{
		[]
		{
			std::cout << "threadC Hello from test" << std::endl;
		}
	};

	threadC.join();
}

void functionB()
{
	std::cout << "functionB" << std::endl;
}

int main()
{
	std::thread threadA{ functionA };
	threadA.join();

	std::thread threadB{ functionB };
	threadB.join();

	return 0;
}