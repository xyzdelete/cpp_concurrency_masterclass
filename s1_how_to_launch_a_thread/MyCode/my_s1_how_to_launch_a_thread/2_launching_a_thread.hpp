#pragma once
#include <iostream>
#include <thread>

void foo()
{
	std::cout << std::this_thread::get_id() << " Hello from foo" << std::endl;
}

class callable_class {

public:
	void operator()()
	{
		std::cout << std::this_thread::get_id() << " Hello from class with function call operator" << std::endl;
	}
};

void run()
{
	std::thread thread1{ foo };

	callable_class obj;
	std::thread thread2{ obj };

	std::thread thread3(
		[]
		{
			std::cout << std::this_thread::get_id() << " Hello from labmda" << std::endl;
		}
	);

	thread1.join();
	thread2.join();
	thread3.join();

	std::cout << std::this_thread::get_id() << " Hello from main" << std::endl;
}