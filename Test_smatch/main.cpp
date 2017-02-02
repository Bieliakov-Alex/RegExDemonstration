/*Тестирование возможностей объекта, предназначенного для получения результатов поиска строк*/

#include <iostream>
#include <string>
#include <regex>
#include <conio.h>

int main()
{
	std::string s("this subject has a submarine as a subsequence");
	std::smatch m;
	std::regex e("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

	std::regex_search(s, m, e);

	//Выводим количество найденных значений:
	int count = m.size();
	std::cout << "Count of matches: " << count << std::endl;

	//Выводим в цикле:
	for (int i = 0;i < count;i++)
	{
		std::cout << "Match " << i + 1 << " : " << m[i] << std::endl;
	}

	_getch();

	return 0;
}