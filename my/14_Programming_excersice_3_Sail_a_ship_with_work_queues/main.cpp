import std;
import thread_guard;
import sail_ship;

int main()
{
	std::size_t command{};
	std::queue<std::size_t> engineWorkQueue{};
	std::queue<std::size_t> cleanWorkQueue{};
	std::thread cleaningCrewThread{};
	std::thread engineCrewThread{};
	cleaningCrewThread = std::move(std::thread{ cleaningCrew, std::ref(command), std::ref(cleanWorkQueue) });
	engineCrewThread = std::move(std::thread{ engineCrew, std::ref(command), std::ref(engineWorkQueue) });
	thread_guard cleaningCrewThreadGuard{ cleaningCrewThread };
	thread_guard engineCrewThreadGuard{ engineCrewThread };
	do
	{
		std::cout << "Available commands:" << std::endl
			<< "DoCleaning = 1" << std::endl
			<< "FullSpeedAhead = 2" << std::endl
			<< "StopTheEngine = 3" << std::endl
			<< "Exit = 100" << std::endl;
		std::cout << "Captain, give a command: " << std::endl;
		std::cin >> command;

		try
		{
			switch (command)
			{
			case CaptainsCommands::DoCleaning:
			{
				cleanWorkQueue.push(static_cast<std::size_t>(command));
				break;
			}
			case CaptainsCommands::FullSpeedAhead:
			case CaptainsCommands::StopTheEngine:
			{
				engineWorkQueue.push(static_cast<std::size_t>(command));
				break;
			}
			case exitCommandCode:
			{
				break;
			}
			default:
			{
				break;
			}
			}

			std::cout << std::endl;
		}
		catch (...)
		{
		}
	}
	while (command != CaptainsCommands::Exit);

	return 0;
}