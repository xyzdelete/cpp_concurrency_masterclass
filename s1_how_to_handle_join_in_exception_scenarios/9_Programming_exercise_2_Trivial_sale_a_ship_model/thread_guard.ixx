export module thread_guard;

import std;

export class thread_guard
{
public:
	thread_guard(const std::thread&) = delete;
	thread_guard& operator=(const thread_guard&) = delete;
	explicit thread_guard(std::thread& thread) : _thread{ thread }
	{

	}
	~thread_guard()
	{
		if (_thread.joinable())
		{
			_thread.join();
		}
	}
private:
	std::thread& _thread;
};