/*Testing separator | */

#include <regex>
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	string input = "<data attr=\"1\">  1 \n 2 </ data>"; //строка входных данных
	smatch result; //объект результатов
	regex pattern("<\\s*?data(?:\\s*?\\s*?>|\\s+?(?:[\x20-\x7E]|[ \t\r\n\v\f])*?\\s*?>)(([\x20-\x7E]|[ \t\r\n\v\f])*?)<\\s*?/\\s*?data\\s*?>"); //Шаблон для поиска элементов

	regex_search(input, result, pattern);

	int count = result.size();
	cout << "Number of results: "<<count << endl;
	for (int i = 0;i < count;i++)
	{
		cout << result[i] << endl;
	}

	_getch();
	return 0;
}