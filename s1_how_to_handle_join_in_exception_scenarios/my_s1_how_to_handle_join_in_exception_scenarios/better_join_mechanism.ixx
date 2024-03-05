export module better_join_mechanism;

#include <iostream>
#include <thread>

class thread_guard
{
	std::thread& t;
public:
	explicit thread_guard(std::thread& _t) : t(_t)
	{

	}
	~thread_guard()
	{
		if (t.joinable())
		{
			t.join();
		}
	}
	thread_guard(thread_guard& const) = delete;
	thread_guard& operator=(thread_guard& const) = delete;
};

void foo()
{
	std::cout << "This is foo operation" << std::endl;
}

void other_operations()
{
	std::cout << "This is other operation" << std::endl;
	throw std::runtime_error("this is a runtime error");
}


export void run()
{
	std::thread foo_thread{ foo };
	thread_guard tg(foo_thread);

	try
	{
		other_operations();
	}
	catch (...)
	{

	}
};
