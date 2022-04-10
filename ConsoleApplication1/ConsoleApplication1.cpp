#include <iostream>
#include <wtypes.h>
//
extern "C" __declspec(dllimport) char* __stdcall GetStr();
//

int main()
{
	HANDLE sEvent = CreateEvent(NULL, FALSE, FALSE, "SendEvent");

	WaitForSingleObject(sEvent, INFINITE);

	char* str = GetStr();

	std::cout << "str: " << str << std::endl;

	std::string o;
	std::cin >> o;
	return 0;
}
