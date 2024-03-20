export module sail_ship;

import std;
import thread_guard;

export
{
	constexpr std::chrono::milliseconds sleepTime{ 3000 };
	constexpr std::chrono::milliseconds sleepTimeLoop{ 1000 };
	constexpr std::size_t exitCommandCode{ 100 };

	enum CaptainsCommands : std::size_t
	{
		DoCleaning = 1,
		FullSpeedAhead = 2,
		StopTheEngine = 3,
		Exit = exitCommandCode
	};


	void cleaningCrew(std::size_t& command, std::queue<std::size_t>& commandQueue)
	{
		while (true)
		{
			if (command == exitCommandCode)
			{
				break;
			}
			std::this_thread::sleep_for(sleepTimeLoop);
			if (!commandQueue.empty())
			{
				switch (commandQueue.front())
				{
				case CaptainsCommands::DoCleaning:
				{
					std::cout << "Cleaning crew is cleaning stuff..." << std::endl;
					std::this_thread::sleep_for(sleepTime);
					std::cout << "Cleaning crew finished cleaning..." << std::endl;
					commandQueue.pop();
					break;
				}
				default:
				{
					break;
				}
				}
			}
		}
	};

	void engineCrew(std::size_t& command, std::queue<std::size_t>& commandQueue)
	{
		while (true)
		{
			if (command == exitCommandCode)
			{
				break;
			}
			std::this_thread::sleep_for(sleepTimeLoop);
			if (!commandQueue.empty())
			{
				switch (commandQueue.front())
				{
				case CaptainsCommands::FullSpeedAhead:
				{
					std::cout << "Engine crew is enabling full speed..." << std::endl;
					std::this_thread::sleep_for(sleepTime);
					std::cout << "Engine crew enabled full speed..." << std::endl;
					commandQueue.pop();
					break;
				}
				case CaptainsCommands::StopTheEngine:
				{
					std::cout << "Engine crew is stopping engine..." << std::endl;
					std::this_thread::sleep_for(sleepTime);
					std::cout << "Engine crew stopped engine..." << std::endl;
					commandQueue.pop();
					break;
				}
				default:
				{
					break;
				}
				}
			}
		}
	};
}