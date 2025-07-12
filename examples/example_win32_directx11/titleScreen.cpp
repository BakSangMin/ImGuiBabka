#include <iostream>
#include <fstream>
#include <string>
#include <imgui.h>
#include <imgui_internal.h>
#include <settingsScreen.h>
#include "global.h"
#include "AchievementsScreen.h"

//Declarations
bool TSOpened = true;

//char* stringToChar(std::string str) {
//    // Allocate memory for the char array
//    char* charArray = new char[str.length() + 1];
//    // Copy the string content to the char array
//    std::strcpy(charArray, str.c_str());
//    return charArray;
//}

void OpenTitleScreen() {
    TSOpened = true;
    CurrentWindow = 1;
    CloseNoncurrentWindow();
}
void CloseTitleScreen() {
    TSOpened = false;
}
void DisplayTitleButtons() {
    ImVec2 winSize(ImGui::GetWindowSize());
    ImVec2 StartBtnSize(300, 70);
    ImVec2 StartBtnPos;
    StartBtnPos.x = (winSize.x - StartBtnSize.x) / 2;
    StartBtnPos.y = 75;
    ImGui::SetCursorPos(StartBtnPos);
    if (ImGui::Button("New Game", StartBtnSize)) {

    }
    StartBtnPos.y = StartBtnPos.y + 100;
    ImGui::SetCursorPos(StartBtnPos);
    if (ImGui::Button("Continue", StartBtnSize)) {

    }
    StartBtnPos.y = StartBtnPos.y + 100;
    ImGui::SetCursorPos(StartBtnPos);
    if (ImGui::Button("Settings", StartBtnSize)) {
        OpenSettingsScreen();
    }
    StartBtnPos.y = StartBtnPos.y + 100/1.3f;
    ImGui::SetCursorPos(StartBtnPos);
    StartBtnSize.x = StartBtnSize.x / 2.05f;
    StartBtnSize.y = StartBtnSize.y / 2;
    if (ImGui::Button("Achievements", StartBtnSize)) {
        OpenAchievementsScreen();
    }
    ImGui::SameLine(0.0f, 10.0f);
    StartBtnPos.x = StartBtnPos.x + (300 - StartBtnSize.x);
    ImGui::SetCursorPos(StartBtnPos);
    if (ImGui::Button("Exit To Desktop", StartBtnSize)) {
        exit(0);
    }
}

void ReadTitleScreen() {
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImVec2 vpPos(viewport->Pos);
    ImVec2 vpSize(viewport->Size);
    vpPos.y = vpPos.y + 19;
    ImGui::SetNextWindowPos(vpPos);
    ImGui::SetNextWindowSize(vpSize);

    if (TSOpened) {
        ImGui::Begin("Start Menu", &TSOpened,
            ImGuiWindowFlags_NoDocking |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoTitleBar);
        std::string titleScreenOut;
        std::ifstream titleScreen("Scenes\\Title Screen.scene");
        try {
            if (titleScreen.is_open() == false) {
                throw 101;
            }

        }
        catch (int thrown) {
            std::cout << "Error" << thrown;
        }

        FileLineOut = 1;
        ReadFile(titleScreen, nullptr);


        DisplayTitleButtons();
 
        if (titleScreen.is_open() == true) {
            titleScreen.close();
        }
        ImGui::End();
    }
}




