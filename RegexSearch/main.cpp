#include <regex>
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	string inputString = "<?xml version=\"1.0\" encoding=\"utf - 8\"?>\n<datachunk>\n<data attr=\"1\" attr2=\"1\">   1   < / data>\n<data>2< / data>\n< / datachunk>\n"; //простой xml с атрибутами
	string inputStringWithoutAttr = "<?xml version=\"1.0\" encoding=\"utf - 8\"?>\n<datachunk>\n<data>   1   < / data>\n<data>2< / data>\n< / datachunk>\n"; //простой xml без атрибутов
	smatch result;
	smatch resultWithoutAttr;
	regex expressionData("<\\s*?data(?:\\s*?>|\\s+?(?:[\x20-\x7E]|[ \t\r\n\v\f])*?\\s*?>)(([\x20-\x7E]|[ \t\r\n\v\f])*?)<\\s*?/\\s*?data\\s*?>");
						 //"<\\s*?data(?:\\s*?>|\\s+?(?:[\x20-\x7E]|[ \t\r\n\v\f])*?\\s*?>(([\x20-\x7E]|[ \t\r\n\v\f])*?)<\\s*?/\\s*?data\\s*?>";
	//regex expressionData("<\\s*?data(?:\\s*?>|\\s+?(?:[\x20-\x7E]|[ \t\r\n\v\f])*?)>");
	//regex expressionData1("<\\s*?data(?:\\s*?>|\\s+?(?:[\x20-\x7E]|[ \t\r\n\v\f])*?)\\s*?>(([\x20-\x7E]|[ \t\r\n\v\f])*?)<\\s*?/\\s*?data\\s*?>");

	regex_search(inputString, result, expressionData);
	regex_search(inputStringWithoutAttr, resultWithoutAttr, expressionData);

	int count = result.size();
	int countWithoutAttr = resultWithoutAttr.size();
	cout << "Count of matches: " << count << endl;

	for (int i = 0;i < count;i++)
	{
		cout << result[i] << endl;
	}
	cout << endl;
	cout << "Count without attributes: " << countWithoutAttr << endl;
	for (int i = 0;i < countWithoutAttr;i++)
	{
		cout << resultWithoutAttr[i] << endl;
	}

	_getch();
	return 0;
}