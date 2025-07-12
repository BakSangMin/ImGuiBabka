#pragma once
#include <string>

// Operational Logic Globals
extern int CurrentWindow;
void CloseNoncurrentWindow();
extern bool WinClosureTitleCheck;
// File Line
extern int FileLineOut;
char* stringToChar(std::string str);
void ReadFile(std::ifstream& file, char* ConvCharOut);
// Player Globals (Player Class)




