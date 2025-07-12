#include <iostream>
#include <fstream>
#include <string>
#include "titleScreen.h"
#include <imgui.h>
#include <imgui_internal.h>
#include "global.h"

bool SSOpened = false;

void OpenSettingsScreen() {
    SSOpened = true;
    CurrentWindow = 2;
    CloseNoncurrentWindow();
}
void CloseSettingsScreen() {
    SSOpened = false;
}

void ReadSettingsScreen() {
    if (SSOpened) {
        ImGui::Begin("Settings", &SSOpened,
            ImGuiWindowFlags_NoDocking |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoMove);

        std::string settingsScreenOut;
        std::ifstream settingsScreen("Scenes\\Settings Screen.scene");
        try {
            if (settingsScreen.is_open() == false) {
                throw 101;
            }

        }
        catch (int thrown) {
            std::cout << "Error" << thrown;
        }

        FileLineOut = 1;
        ReadFile(settingsScreen, nullptr);
        if (ImGui::Button("Button1")) {

        }
        FileLineOut = 2;
        ReadFile(settingsScreen, nullptr);
        if (ImGui::Button("Button2")) {

        }


        if (settingsScreen.is_open() == true) {
            settingsScreen.close();
        }
        ImGui::End();
    }
    if (CurrentWindow == 2 && !SSOpened) {
        OpenTitleScreen();
    }
}






