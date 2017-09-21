#include<Windows.h>
#include<direct.h>
#include<tchar.h>
#include<iostream>

using namespace std;
class GameApp { 
	
private:
	static GameApp* self;
	GameApp() {};
	
public:
    static GameApp* GetInstance();
    void initializeApp();
	void checkStorage(const int);
	void checkMemory();
    void checkCPU();

};

int main() {
	GameApp* game = GameApp::GetInstance();

	game->initializeApp();

	system("Pause");
}
GameApp* GameApp::self = NULL;


void GameApp::initializeApp() {

	checkStorage(300);
    checkMemory();
	checkCPU();
    
}
GameApp* GameApp::GetInstance() {
	if (self == NULL) {
		self = new GameApp();
		cout << "First instance of game" << endl;
	}
	else
		cout << "Game Already Open" << endl;
	return self;

}
void GameApp::checkStorage(const int diskSpaceNeeded) {
    __int64 lpFreeBytesAvailable, lpTotalNumberOfBytes, lpTotalNumberOfFreeBytes;
    GetDiskFreeSpaceEx(NULL, (PULARGE_INTEGER)&lpFreeBytesAvailable, (PULARGE_INTEGER)&lpTotalNumberOfBytes, (PULARGE_INTEGER)&lpTotalNumberOfFreeBytes);
    int diskAvailable = lpFreeBytesAvailable / (1024 * 1024);
    if (diskAvailable < diskSpaceNeeded)
       cout << "You don't have 300MB of free space." << endl;
    else
       cout << "You have free space available." << endl;

}
void GameApp::checkMemory() {
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);
	_tprintf(TEXT("There are %*I64d free  MB of virtual memory.\n"), 7, status.ullAvailVirtual / (1024 * 1024));
	_tprintf(TEXT("There are %*I64d total MB of physical memory.\n"), 7, status.ullTotalPhys / (1024 * 1024));
}


void GameApp::checkCPU()
{
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;
	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);
	if (lError == ERROR_SUCCESS)
	{
		// query the key:
		RegQueryValueEx(hKey, "~Mhz", NULL, &type, (LPBYTE)&dwMHz, &BufSize);
	}
	cout << "CPU speed at ";
	cout << dwMHz;
	cout << "MHz." << endl;
}

