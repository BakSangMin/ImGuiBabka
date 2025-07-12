#include <iostream>
#include <fstream>
#include <string>
#include "titleScreen.h"
#include <imgui.h>
#include <imgui_internal.h>
#include "global.h"
#include "settingsScreen.h"

bool AchOpened = false;

void OpenAchievementsScreen() {
    AchOpened = true;
    CurrentWindow = 3;
    CloseNoncurrentWindow();
}
void CloseAchievementsScreen() {
    AchOpened = false;
}
void ReadAchievementsScreen() {
    if (AchOpened) {
        ImGui::Begin("Achievements", &AchOpened,
            ImGuiWindowFlags_NoDocking |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoMove);

        std::string AchievementScreenOut;
        std::ifstream achievementsScreen("Scenes\\Achievements Screen.scene");
        try {
            if (achievementsScreen.is_open() == false) {
                throw 101;
            }

        }
        catch (int thrown) {
            std::cout << "Error" << thrown;
        }

        ImGui::Text("HELLOWORLD!");


        if (achievementsScreen.is_open() == true) {
            achievementsScreen.close();
        }
        ImGui::End();
    }
    if (CurrentWindow == 3 && !AchOpened) {
        OpenTitleScreen();
    }
}






