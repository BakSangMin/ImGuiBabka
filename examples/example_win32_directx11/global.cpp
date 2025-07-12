#pragma once
#include "global.h"
#include "titleScreen.h"
#include "settingsScreen.h"
#include "AchievementsScreen.h"
#include <string>
#include <fstream>
#include <iostream>
#include <imgui.h>

int CurrentWindow = 0;
bool WinClosureTitleCheck = false;
int FileLineOut = 0;

void CloseNoncurrentWindow() {
    switch (CurrentWindow) {
    case 1:                                 // Title
        CloseSettingsScreen();
        CloseAchievementsScreen();
        break;
    case 2:                                 // Settings
        CloseTitleScreen();
        CloseAchievementsScreen();
        break;
    case 3:                                 // Achievements
        CloseTitleScreen();
        CloseSettingsScreen();
        break;
    default:                                //
        break;
    }
}
char* stringToChar(std::string str) {
    // Allocate memory for the char array
    char* charArray = new char[str.length() + 1];
    // Copy the string content to the char array
    std::strcpy(charArray, str.c_str());
    return charArray;
}
void ReadFile(std::ifstream& file, char* ConvCharOut) {
    int currentFileLine{ 0 };
    while (currentFileLine != FileLineOut) {
        currentFileLine = currentFileLine + 1;
    }
    if (currentFileLine == FileLineOut) {
        std::string SceneOut;
        std::getline(file, SceneOut);
        char* ConvCharOut = stringToChar(SceneOut);
        ImGui::TextWrapped(ConvCharOut = stringToChar(SceneOut));
        delete[] ConvCharOut;
    }
}
