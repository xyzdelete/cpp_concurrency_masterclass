export module Module;

import std;

export
{
	void func_2(const int& x) noexcept
	{
		while (true)
		{
			try
			{
				std::cout << x << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds{ 1000 });
			}
			catch (...)
			{
				throw std::runtime_error{ "This is a runtime error" };
			}
		}
	}

	void func_1() noexcept
	{
		int x{ 5 };
		std::thread thread_2{ func_2, std::ref(x) };
		thread_2.detach();
		std::this_thread::sleep_for(std::chrono::milliseconds{ 1000 });
		std::cout << "thread 1 finished execution" << std::endl;
	}

	void run() noexcept
	{
		std::thread thread_1{ func_1 };
		thread_1.join();
	}
}