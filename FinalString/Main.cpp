#include <iostream>
#include <string>

// ������ 1.
std::string spaces_str(std::string str);

// ������ 2.
bool is_spam(std::string str);


int main(){
	setlocale(LC_ALL, "Russian");
	int n;

	// ������ 1. ������� ��������.
	/*std::cout << "������ 1.\n������� ������ -> ";
	std::string str1;
	std::getline(std::cin, str1); // ��� ������� ������ ������ �����.
	std::cout << spaces_str(str1) << "\n\n";*/
	
	// ������ 2. �������� �� ����.
	/*std::cout << "������ 2.\n������� ������ '-(0_0)-> ";
	std::string str2;
	std::getline(std::cin, str2);
	if (is_spam(str2))
		std::cout << "����������� ������\n\n";
	else
		std::cout << "����� �� ����������.\n\n";*/

	// ������ 3. �������� URL.
	std::cout << "������ 3.\n\n������: ";
	std::string URL = "http://google.com/search/results";
	std::cout << URL << std::endl;

	int domen_index = URL.find("://") + 3;
	int path_index = URL.find("/", domen_index) + 1;

	std::string protocol = URL.substr(0, domen_index - 3);
	std::string domen = URL.substr(domen_index, path_index - 1 - domen_index);
	std::string path = URL.substr(path_index);

	std::cout << "��������: " << protocol << std::endl;
	std::cout << "�����: " << domen << std::endl;
	std::cout << "����: " << path << std::endl;

	return 0;
}

// ������ 1.
std::string spaces_str(std::string str) {
	std::string result; // ""
	for (int i = 0; i < str.length(); i++) {
		result += str[i];
		if (i != str.length() - 1)
			result += ' ';
	}
	return result;
}

// ������ 2.
bool is_spam(std::string str) {
	for (int i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
	static const int spams_number = 4;
	static std::string spams[spams_number]{ // �������� ������������.
		"100% free",
		"sales increase",
		"only today",
		"black friday"
	};
	for (int i = 0; i < spams_number; i++)
		if (str.find(spams[i]) < str.length())
			return true; // ���� ����.
	return false; // ����� ���.
}