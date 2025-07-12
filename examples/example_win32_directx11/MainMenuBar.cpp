#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <d3d11.h>
#include <tchar.h>
#include "titleScreen.h"
#include "MainMenuBar.h"
#include "settingsScreen.h"
#include "global.h"
#include "AchievementsScreen.h"

void MainMenuBar() {
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("Menu")) {
            if(ImGui::MenuItem("Back to Title", "This will be a shortcut")) {
                OpenTitleScreen();
            }
            if (ImGui::MenuItem("Open Settings", "This will be a shortcut")) {
                OpenSettingsScreen();
            }
            if (ImGui::MenuItem("Open Achievements", "Shortcut")) {
                OpenAchievementsScreen();
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}



//if (ImGui::BeginMenu("Menu")) {
//    if (ImGui::MenuItem("Back to Title")) {
//        OpenTitleScreen();
//        if (SettingsOpenedFromTitle = true) {
//            CloseSettingsScreen();
//        }
//    }
//    if (ImGui::MenuItem("Open Settings")) {
//        OpenSettingsScreen();
//    }ImGui::EndMenu();
//    ImGui::EndMainMenuBar();
