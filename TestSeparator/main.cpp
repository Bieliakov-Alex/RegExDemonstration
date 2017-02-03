/*Testing separator | */

#include <regex>
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	string input = "<?xml version=\"1.0\" encoding=\"utf - 8\"?>\n<datachunk>\n<data>   1   < / data>\n<data>2< / data>\n< / datachunk>\n"; //строка входных данных
	smatch result; //объект результатов
	regex pattern("<\\s*?data(?:\\s*?>|\\s+?(?:[\x20-\x7E]|[ \t\r\n\v\f])*?\\s*?>)(([\x20-\x7E]|[ \t\r\n\v\f])*?)<\\s*?/\\s*?data\\s*?>"); //Шаблон для поиска элементов

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