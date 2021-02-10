#include <iostream>
#include <string>
#include "deque.h"

int main()
{
	std::string line;
	deque* my_deque = new deque;

	while (true)
	{
		if (std::cin.eof())
			break;

		std::getline(std::cin, line);

		if (line == "exit")
			break;

		int first_pos = line.find(" ");
		std::string cmd = line.substr(0, first_pos);

		if (cmd == "size") {
			std::cout << "size is " << my_deque->get_size() << std::endl;
		}

		if (cmd == "front") {
			std::cout << my_deque->get_front() << std::endl;
		}

		if (cmd == "back") {
			std::cout << my_deque->get_back() << std::endl;
		}

		if (cmd == "empty") {
			std::cout << "empty " << my_deque->is_empty() << std::endl;
		}

		if (cmd == "print") {
			my_deque->print_deque();
		}

		if (cmd == "find") {
			std::string name_to_find;
			for (int i{ first_pos + 2 }; line[i] != '\"'; i++) {
				name_to_find.push_back(line[i]);
			}
			my_deque->find_url(name_to_find);
		}

		if ((cmd == "push_front") || (cmd == "push_back")) {
			std::string name_to_push;
			std::string url_to_push;
			int second_pos{ 0 };
			for (int i{ first_pos + 2 }; line[i] != '\"'; i++) {
				name_to_push.push_back(line[i]);
				second_pos = i;
			}
			for (int i{ second_pos + 4 }; line[i] != '\"'; i++) {
				url_to_push.push_back(line[i]);
			}
			//testing output
			//std::cout << "name_to_push is " << name_to_push << ", " << "url_to_push is " << url_to_push << std::endl;

			if (cmd == "push_front")
				my_deque->push_front(name_to_push, url_to_push);

			if (cmd == "push_back")
				my_deque->push_back(name_to_push, url_to_push);
		}

		if (cmd == "pop_front") {
			my_deque->pop_front();
		}

		if (cmd == "pop_back") {
			my_deque->pop_back();
		}

		if (cmd == "clear") {
			my_deque->clear_deque();
			std::cout << "success" << std::endl;
		}

		//_CrtDumpMemoryLeaks();
	}

	delete my_deque;
	my_deque = nullptr;

	return 0;
}