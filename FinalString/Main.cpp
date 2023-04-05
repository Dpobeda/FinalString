#include <iostream>
#include <string>

// Задача 1.
std::string spaces_str(std::string str);

// Задача 2.
bool is_spam(std::string str);


int main(){
	setlocale(LC_ALL, "Russian");
	int n;

	// Задача 1. Вставка пробелов.
	/*std::cout << "Задача 1.\nВведите строку -> ";
	std::string str1;
	std::getline(std::cin, str1); // Даёт вводить больше одного слова.
	std::cout << spaces_str(str1) << "\n\n";*/
	
	// Задача 2. Проверка на спам.
	/*std::cout << "Задача 2.\nВведите строку '-(0_0)-> ";
	std::string str2;
	std::getline(std::cin, str2);
	if (is_spam(str2))
		std::cout << "Обнаруженна правда\n\n";
	else
		std::cout << "Спама не обнаружено.\n\n";*/

	// Задача 3. Расбивка URL.
	std::cout << "Задача 3.\n\nАдресс: ";
	std::string URL = "http://google.com/search/results";
	std::cout << URL << std::endl;

	int domen_index = URL.find("://") + 3;
	int path_index = URL.find("/", domen_index) + 1;

	std::string protocol = URL.substr(0, domen_index - 3);
	std::string domen = URL.substr(domen_index, path_index - 1 - domen_index);
	std::string path = URL.substr(path_index);

	std::cout << "Протокол: " << protocol << std::endl;
	std::cout << "Домен: " << domen << std::endl;
	std::cout << "Путь: " << path << std::endl;

	return 0;
}

// Задача 1.
std::string spaces_str(std::string str) {
	std::string result; // ""
	for (int i = 0; i < str.length(); i++) {
		result += str[i];
		if (i != str.length() - 1)
			result += ' ';
	}
	return result;
}

// Задача 2.
bool is_spam(std::string str) {
	for (int i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
	static const int spams_number = 4;
	static std::string spams[spams_number]{ // Спамовое словачитание.
		"100% free",
		"sales increase",
		"only today",
		"black friday"
	};
	for (int i = 0; i < spams_number; i++)
		if (str.find(spams[i]) < str.length())
			return true; // Спам есть.
	return false; // Спама нет.
}