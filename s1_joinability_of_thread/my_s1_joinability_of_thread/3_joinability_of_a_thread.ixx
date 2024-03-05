export module s1_joinability_of_thread;

import std;

export
{
	void test()
	{
		std::cout << "Hello from test" << std::endl;
	};

	void run()
	{
		std::thread thread1{ test };

		if (thread1.joinable())
		{
			std::cout << "thread1 is joinable" << std::endl;
		}
		else
		{
			std::cout << "thread1 is not joinable" << std::endl;
		}

		thread1.join();

		if (thread1.joinable())
		{
			std::cout << "thread1 is joinable" << std::endl;
		}
		else
		{
			std::cout << "thread1 is not joinable" << std::endl;
		}

		std::thread thread2{};
		if (thread1.joinable())
		{
			std::cout << "thread2 is joinable" << std::endl;
		}
		else
		{
			std::cout << "thread2 is not joinable" << std::endl;
		}
	};
}