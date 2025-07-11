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

        ImGui::TextWrapped("Testing");

        ImGui::End();
    }
    if (SettingsOpenedFromTitle == true && SSOpened == false) {
        OpenTitleScreen();
    }
}






