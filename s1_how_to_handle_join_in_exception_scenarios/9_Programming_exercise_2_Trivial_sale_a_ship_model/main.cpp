import std;
import thread_guard;
import sail_ship;

int main()
{
	std::size_t command{};
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
			run(static_cast<CaptainsCommands>(command));
			std::cout << std::endl;
		}
		catch (...)
		{
		}
	}
	while (command != CaptainsCommands::Exit);

	return 0;
}