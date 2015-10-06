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
	/*chdir("c:");
	//system("C:");
	//system("cd V:\Desktop");
	//system("dir");
	system("cd C:\Program Files (x86)\Internet Explorer");
	system("dir");
	system("iexplore.exe pandora.com");
	system("pause");*/
	ChangeDirectory("C:/Program Files (x86)/Internet Explorer");

	int c;
	cin >> c;

	return 0;

}



int ChangeDirectory(const char *url){
	const int bufferSize = MAX_PATH;
	char oldDir[bufferSize]; // store the current directory

	// get the current directory, and store it
	if (!GetCurrentDirectory(bufferSize, oldDir)) {
		cerr << "Error getting current directory: #" << GetLastError();
		return 1; // quit if it failed
	}
	cout << "Current directory: " << oldDir << '\n';
	//string urlNew = "("+url+")";
	// new directory
	const char* newDir = R"(C:/Program Files (x86)/Internet Explorer)";
	if (!SetCurrentDirectory(url)) {
		cerr << "Error setting current directory: #" << GetLastError();
		return 1; // quit if we couldn't set the current directory
	}
	cout << "Set current directory to " << newDir << '\n';

	system("dir");
	// Reset the current directory back to what it was.
	if (!SetCurrentDirectory(oldDir)) {
		cerr << "Error resetting current directory: #" << GetLastError();
		return 1;
	}
	cout << "Reset current directory. \n";

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
