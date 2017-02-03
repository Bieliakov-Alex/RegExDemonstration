#include <regex>
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	string inputString = "<?xml version=\"1.0\" encoding=\"utf - 8\"?>\n<datachunk>\n<data>   1   < / data>\n<data>2< / data>\n< / datachunk>\n"; //простой xml
	smatch result;
	//regex expressionData("<\\s*data\\s*>[:alnum:]*<\\s*/\\s*data\\s*>");
	regex expressionData("<\\s*?data\\s*?>(([\x20-\x7E]|[ \t\r\n\v\f])*?)<\\s*?/\\s*?data\\s*?>");

	regex_search(inputString, result, expressionData);

	int count = result.size();
	std::cout << "Count of matches: " << count << std::endl;

	for (int i = 0;i < count;i++)
	{
		std::cout << result[i] << std::endl;
	}

	_getch();
	return 0;
}