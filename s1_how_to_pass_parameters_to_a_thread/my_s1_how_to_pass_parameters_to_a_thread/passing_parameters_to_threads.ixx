export module passing_parameters_to_threads;

import std;

export
{
	void func_1(int x, int y) noexcept
	{
		std::cout << "X + Y = " << x + y << std::endl;
	}

	void func_2(const int& x) noexcept
	{
		while (true)
		{
			std::cout << "Thread 1 value of X - " << x << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	}


	void run() noexcept
	{
		int x{ 9 };
		std::cout << "Main thread value of X - " << x << std::endl;

		std::thread thread_1{ func_2, std::ref(x) };
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		x = 15;
		std::cout << "Main thread value of X has been changed to - " << x << std::endl;
		thread_1.join();
	}
}
