export module Transfering_ownership_of_a_thread;

import std;

export
{
	void foo()
	{
		std::cout << "Foo" << std::endl;
	}
	void bar()
	{
		std::cout << "Bar" << std::endl;
	}
	void run()
	{
		std::thread thread_1{ foo };

		std::thread thread_2 = std::move(thread_1);

		thread_1 = std::thread{ bar };
		std::thread thread_3{ foo };

		thread_1 = std::move(thread_3);

		thread_1.join();
		thread_2.join();
		thread_3.join();
	}
}