#include "input validation.h"

namespace input_checker {
	int check_number(std::string s) {
		try {
			for (int i = 0; i < s.length(); i++) {
				if (!isdigit(s[i])) {
					throw 1;
				}
			}
		}
		catch (int e) {
			return 0;
		}
		return 1;
	}

	/*int is_input_valid(std::string input, int allowed_options) {
		
		bool number_passed_both_tests = false;
		do {
			//check it's a number
			std::cin >> input;
			while (!check_number(input)) {
				std::cout << "Please enter a valid number" << std::endl;
				std::cin.clear();
				std::cin.ignore();
				std::cin >> input;
				check_number(input);
			}
			//check value is in allowed range
			int string_to_int = stoi(input);
			if (string_to_int > allowed_options) {
				std::cout << "Error. Choice is out of range. Enter again\n" << std::endl;
				std::cin.clear();
				std::cin.ignore();
				number_passed_both_tests = false;
			}
			else { number_passed_both_tests = true; }
		} while (!number_passed_both_tests);
		
		return 0;
	}

/*	int take_user_input(std::string s, int allowed_options) {
		std::string userinput;

		std::cin >> userinput;
		bool valid_input = false;
		do {
			valid_input = is_input_valid(userinput, 2);
		} while (!valid_input);
	}
	*/
}