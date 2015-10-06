#include <Windows.h>
#include <iostream>
using namespace std;

int ChangeDirectory(const char* url);
void LeftClick();
int main(){
	const int bufferSize = MAX_PATH;
	char oldDir[bufferSize]; // store the current directory

	// get the current directory, and store it
	if (!GetCurrentDirectory(bufferSize, oldDir)) {
		cerr << "Error getting current directory: #" << GetLastError();
		return 1; // quit if it failed
	}

	cout << "Current directory: " << oldDir << '\n';
	

	ChangeDirectory("C:/Program Files (x86)/Internet Explorer");
	system("iexplore.exe pandora.com");
	ChangeDirectory(oldDir);
	system("pause");
	int c;
	cin >> c;

	return 0;

}



int ChangeDirectory(const char *url){
	const char* newDir = R"(C:/Program Files (x86)/Internet Explorer)";
	if (!SetCurrentDirectory(url)) {
		cerr << "Error setting current directory: #" << GetLastError();
		return 1; // quit if we couldn't set the current directory
	}
	cout << "Set current directory to " << newDir << '\n';

}
void LeftClick(){
	INPUT    Input = { 0 };
	// left down 
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	::SendInput(1, &Input, sizeof(INPUT));

	// left up
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &Input, sizeof(INPUT));
}
