#include <iostream>
#include <fstream>
#include <string>
#include "titleScreen.h"
#include <imgui.h>
#include <imgui_internal.h>
#include "global.h"

bool SSOpened = false;
bool SSCloseClick = false;

void OpenSettingsScreen() {
    SSOpened = true;
}
void CloseSettingsScreen() {
    SSOpened = false;
}
void ReadSettingsScreen() {
    if (SSOpened) {
        ImGui::Begin("Start Menu", &SSOpened,
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




        if (settingsScreen.is_open() == true) {
            settingsScreen.close();
        }
        ImGui::End();
    }


    if (SettingsOpenedFromTitle == true && SSOpened == false) {
        OpenTitleScreen();
    }
}






