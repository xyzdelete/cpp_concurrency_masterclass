export module sail_ship;

import std;
import thread_guard;

export
{
	constexpr std::chrono::milliseconds sleepTime{ 3000 };

	enum CaptainsCommands : std::size_t
	{
		DoCleaning = 1,
		FullSpeedAhead = 2,
		StopTheEngine = 3,
		Exit = 100
	};


	void cleaningCrew(const CaptainsCommands& command)
	{
		switch (command)
		{
			case CaptainsCommands::DoCleaning:
			{
				std::cout << "Cleaning crew is cleaning stuff..." << std::endl;
				std::this_thread::sleep_for(sleepTime);
				std::cout << "Cleaning crew finished cleaning..." << std::endl;
				break;
			}
			default:
			{
				break;
			}
		}
	};

	void engineCrew(const CaptainsCommands& command)
	{
		switch (command)
		{
			case CaptainsCommands::FullSpeedAhead:
			{
				std::cout << "Engine crew is enabling full speed..." << std::endl;
				std::this_thread::sleep_for(sleepTime);
				std::cout << "Engine crew enabled full speed..." << std::endl;
				break;
			}
			case CaptainsCommands::StopTheEngine:
			{
				std::cout << "Engine crew is stopping engine..." << std::endl;
				std::this_thread::sleep_for(sleepTime);
				std::cout << "Engine crew stopped engine..." << std::endl;
				break;
			}
			default:
			{
				break;
			}
		}
	};

	void run(const CaptainsCommands& command)
	{
		switch (command)
		{
			case CaptainsCommands::DoCleaning:
			{
				// Clean and not wait
				std::thread cleaningCrewThread{ cleaningCrew, DoCleaning };
				thread_guard cleaningCrewThreadGuard(cleaningCrewThread);
				
				std::cout << "Non-blocking concurrency" << std::endl;
				break;
			}
			case CaptainsCommands::FullSpeedAhead:
			{
				// full speed wait stop the engine wait
				std::thread engineCrewThread1{ engineCrew, FullSpeedAhead };
				engineCrewThread1.join();
				std::this_thread::sleep_for(sleepTime);
				std::thread engineCrewThread2{ engineCrew, StopTheEngine };
				engineCrewThread2.join();
				break;
			}
			case CaptainsCommands::StopTheEngine:
			{
				std::thread engineCrewThread{ engineCrew, StopTheEngine };
				engineCrewThread.join();
				break;
			}
			default:
			{
				break;
			}
		}
	};
}