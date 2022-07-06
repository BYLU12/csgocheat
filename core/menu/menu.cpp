#include "pch.h"
#include "includes.h"
#include "customfunctions.h"
#include "graph.h"

Menu g_Menu;

void Menu::ApplyStyle() {
	// apply style
	style = &ImGui::GetStyle();

	style->WindowPadding = ImVec2(15, 15);
	//style->WindowRounding = 5.0f;
	style->FramePadding = ImVec2(5, 5);
	//style->FrameRounding = 4.0f;
	style->ItemSpacing = ImVec2(6, 4);
	style->ItemInnerSpacing = ImVec2(4, 3);
	style->IndentSpacing = 25.0f;
	style->ScrollbarSize = 15.0f;
	//style->ScrollbarRounding = 9.0f;
	style->GrabMinSize = 5.0f;
	//style->GrabRounding = 3.0f;

	style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
	style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
	style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	style->Colors[ImGuiCol_FrameBg] = ImVec4(0.34f, 0.0f, 0.69f, 1.00f);
	style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.44f, 0.07f, 0.79f, 1.00f);
	style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.64f, 0.27f, 0.8f, 1.00f);
	style->Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
	style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_Button] = ImVec4(0.34f, 0.0f, 0.69f, 1.00f);
	style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.44f, 0.07f, 0.79f, 1.00f);
	style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.64f, 0.27f, 0.8f, 1.00f);
	style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
}

void Menu::Render() {
	ApplyStyle();

	// start frame and render to screen
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	// call our menu
	std::string menuname = XOR("RayBot | ") + g_Config.activeconfig + XOR("###MainWindow");

	ImGui::Begin(menuname.c_str(), &g_Menu.bToggled);
	g_Menu.Draw();
	ImGui::End();

	// Render dear imgui into screen
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

void Menu::Draw() {
	ImVec2 vSize = ImGui::GetWindowSize();
	if (!style)
		ImGui::Render();

	RenderClickableButtons({ XOR("Ragebot"), XOR("Legitbot"), XOR("ESP"), XOR("Misc")}, &g_Menu.iCurrentTab, vSize, style->WindowPadding.x - 3);
	ImGui::NewLine();

	// Render the playerlist
	g_PlayerList.DrawPlayerList();

	switch (g_Menu.iCurrentTab) {
		// RAGEBOT
	case 0: {
		ImGui::BeginChild(XOR("Main-Ragebot"), ImVec2(vSize.x / 2 - style->WindowPadding.x - 2, 0.f), true);
		ImGui::Text(XOR("Main Ragebot"));
		ImGui::EndChild();

		ImGui::SameLine();
		ImGui::BeginChild(XOR("Weapon-Config"), ImVec2(vSize.x / 2 - style->WindowPadding.x - 2, 0.f), true);
		ImGui::Text(XOR("Weapon-Config"));
		ImGui::EndChild();
	}
		break;
		//LEGITBOT
	case 1: {
		ImGui::BeginChild(XOR("Main-Legitbot"), ImVec2(vSize.x / 2 - style->WindowPadding.x - 2, 0.f), true);
		ImGui::Text(XOR("Main Legitbot"));
		ImGui::Checkbox(XOR("Legitbot"), (bool*)&g_Config.ints[XOR("legitbot")].val);
		//ImGui::SameLine();
		ImGui::Hotkey(XOR("Legitbot-Key"), & g_Config.ints["legitbotkey"].val);
		DrawExtendableGraph(XOR("[Extended] AimbotCurve"), XOR("Distance"), XOR("Speed"), XOR("AimbotCurve"), g_LegitBot.bGraphExtended, g_LegitBot.vAimbotCurve, g_Config.graphs["legitgraph"].val, g_Config.floats["legitgraphmax"].val, LegitbotFunction);
		MultiSelectCombo(XOR("Hitboxes"), { XOR("Head"), XOR("Chest"), XOR("Stomach"), XOR("Legs") }, (bool*)g_Config.arrints[XOR("legithitboxes")].val, 4);
		
		static const char* pLagRecordSelection[] = { "Closest", "First", "Last" };
		ImGui::Combo(XOR("Lagcomp Mode"), &g_Config.ints[XOR("legitlagcompmode")].val, pLagRecordSelection, IM_ARRAYSIZE(pLagRecordSelection));
		ImGui::Checkbox(XOR("Triggerbot"), (bool*)&g_Config.ints[XOR("triggerbot")].val);
		//ImGui::SameLine();
		ImGui::Hotkey(XOR("Triggerbot-Key"), &g_Config.ints[XOR("triggerbotkey")].val);
		ImGui::EndChild();

		ImGui::SameLine();
		ImGui::BeginChild(XOR("Weapon-Config"), ImVec2(vSize.x / 2 - style->WindowPadding.x - 2, 0.f), true);
		
		ImGui::Text(XOR("Weapon-Config"));
		RenderClickableButtons({ XOR("Sniper"), XOR("Rifle"), XOR("Pistol") }, &g_LegitBot.iMenuWeapon, ImVec2{vSize.x / 2, vSize.y}, style->WindowPadding.x + 5);
		ImGui::SliderFloat(XOR("Legitbot Smoothing"), &g_Config.arrfloats[XOR("legitsmoothing")].val[g_LegitBot.iMenuWeapon], 1.f, 100.f, "%.0f%", 1.f);
		ImGui::SliderFloat(XOR("Legitbot FOV"), &g_Config.arrfloats[XOR("legitfov")].val[g_LegitBot.iMenuWeapon], 0.f, 180.f, "%.0f%", 1.f);
		ImGui::SliderFloat(XOR("Legitbot RCS"), &g_Config.arrfloats[XOR("legitrcs")].val[g_LegitBot.iMenuWeapon], 0.f, 100.f, "%.0f%", 1.f);
		ImGui::EndChild();
	}
		  break;
		  //ESP
	case 2: {
		ImGui::BeginChild(XOR("Main-ESP"), ImVec2(vSize.x / 2 - style->WindowPadding.x - 2, 0.f), true);
		ImGui::Text(XOR("Main ESP"));
		ImGui::Checkbox(XOR("Box ESP"), (bool*)&g_Config.ints[XOR("boxesp")].val);
		ImGui::Checkbox(XOR("Name ESP"), (bool*)&g_Config.ints[XOR("nameesp")].val);
		ImGui::Checkbox(XOR("Health ESP"), (bool*)&g_Config.ints[XOR("healthesp")].val);

		ImGui::Checkbox(XOR("Enemy Glow			 "), (bool*)&g_Config.ints[XOR("enemyglow")].val);
		ImGui::SameLine();
		ImGui::ColorEdit4(XOR("Enemy Col"), g_Config.arrfloats[XOR("enemyglowcol")].val, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs);
		
		ImGui::Checkbox(XOR("Friendly Glow		  "), (bool*)&g_Config.ints[XOR("friendlyglow")].val);
		ImGui::SameLine();
		ImGui::ColorEdit4(XOR("Friendly Col"), g_Config.arrfloats[XOR("friendlyglowcol")].val, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs);

		ImGui::Checkbox(XOR("Weapon Glow		    "), (bool*)&g_Config.ints[XOR("weaponglow")].val);
		ImGui::SameLine();
		ImGui::ColorEdit4(XOR("Weapon Col"), g_Config.arrfloats[XOR("weaponglowcol")].val, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs);
		ImGui::EndChild();

		ImGui::SameLine();
		ImGui::BeginChild(XOR("Chams"), ImVec2(vSize.x / 2 - style->WindowPadding.x - 2, 0.f), true);
		ImGui::Text(XOR("Chams"));
		static const char* pChamMode[] = { "Enemy", "Local", "Friendly" };
		ImGui::Combo(XOR("Cham Mode"), &g_Chams.iChamsMode, pChamMode, IM_ARRAYSIZE(pChamMode));

		static const char* pChamTypes[] = { "debugambientcube", "debugdrawflat" };
		ImGui::Combo(XOR("Chams Type"), &g_Config.ints[XOR("chamtype")].val, pChamTypes, IM_ARRAYSIZE(pChamTypes));

		switch(g_Chams.iChamsMode) {
		case 0: {
			ImGui::Checkbox(XOR("Enemy Chams Vis		  "), (bool*)&g_Config.ints[XOR("enemychamsvis")].val);
			ImGui::SameLine();
			ImGui::ColorEdit4(XOR("Vis Col"), g_Config.arrfloats[XOR("enemyviscol")].val, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs);

			ImGui::Checkbox(XOR("Enemy Chams Invis		"), (bool*)&g_Config.ints[XOR("enemychamsinvis")].val);
			ImGui::SameLine();
			ImGui::ColorEdit4(XOR("Invis Col"), g_Config.arrfloats[XOR("enemyinviscol")].val, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs);

			ImGui::Checkbox(XOR("Lagcomp Chams"), (bool*)&g_Config.ints[XOR("lagcompchams")].val);
			if (g_Config.ints[XOR("lagcompchams")].val) {
				static const char* pLagcompchamsMode[] = { "Fast", "Fancy" };
				ImGui::Combo(XOR("Lagcompchams Type"), &g_Config.ints[XOR("lagcompchamstype")].val, pLagcompchamsMode, IM_ARRAYSIZE(pLagcompchamsMode));
			}
		}
			break;
		case 1: {
			ImGui::Checkbox(XOR("Local Chams    		  "), (bool*)&g_Config.ints[XOR("localchams")].val);
			ImGui::SameLine();
			ImGui::ColorEdit4(XOR("Col"), g_Config.arrfloats[XOR("localcol")].val, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs);
		}
			break;
		case 2: {
			ImGui::Checkbox(XOR("Friendly Chams 		  "), (bool*)&g_Config.ints[XOR("friendlychamsvis")].val);
			ImGui::SameLine();
			ImGui::ColorEdit4(XOR("Vis Col"), g_Config.arrfloats[XOR("friendlyviscol")].val, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs);

			ImGui::Checkbox(XOR("Friendly Chams Invis	 "), (bool*)&g_Config.ints[XOR("friendlychamsinvis")].val);
			ImGui::SameLine();
			ImGui::ColorEdit4(XOR("Invis Col"), g_Config.arrfloats[XOR("friendlyinviscol")].val, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs);
		}
			break;
		}


		ImGui::EndChild();
	}
		  break;
		  //MISC
	case 3: {
		ImGui::BeginChild(XOR("Main-Misc"), ImVec2(vSize.x / 2 - style->WindowPadding.x - 2, 0.f), true);
		ImGui::Text(XOR("Main Misc"));
		ImGui::Checkbox(XOR("Bunnyhop"), (bool*)&g_Config.ints[XOR("bunnyhop")].val);
		ImGui::Checkbox(XOR("Lagcompensation"), (bool*)&g_Config.ints[XOR("lagcomp")].val);
		ImGui::Checkbox(XOR("Watermark"), (bool*)&g_Config.ints[XOR("watermark")].val);
		ImGui::EndChild();

		ImGui::SameLine();
		ImGui::BeginChild(XOR("Config"), ImVec2(vSize.x / 2 - style->WindowPadding.x - 2, 0.f), true);
		ImGui::Text(XOR("Config"));

		g_Config.configs.clear();
		static char path[MAX_PATH];
		std::string folder;
		std::string ext = ".ini";

		if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, 0, path)))
			folder = std::string(path) + XOR("\\raybot\\");
		for (auto& p : std::filesystem::recursive_directory_iterator(folder)) {
			if (p.path().extension() == ext)
				g_Config.configs.push_back(p.path().stem().string());
		}

		char** CConfigArr = new char* [g_Config.configs.size()];
		for (size_t i = 0; i < g_Config.configs.size(); i++) {
			CConfigArr[i] = new char[g_Config.configs[i].size() + 1];
			strcpy(CConfigArr[i], g_Config.configs[i].c_str());
		}

		ImGui::PushItemWidth(-1);
		ImGui::ListBox(XOR(""), &g_Config.iSelConfig, &CConfigArr[0], g_Config.configs.size(), 5);
		ImGui::NewLine();
		static std::string name;
		ImGui::PushStyleColor(ImGuiCol_TextDisabled, IM_COL32(150, 150, 150, 255));
		ImGui::InputTextWithHint(XOR(""), XOR("Config Name"), &name);
		ImGui::PopItemWidth();
		ImGui::PopStyleColor();
		if (ImGui::Button(XOR("Save"), ImVec2(vSize.x / 6 - style->WindowPadding.x - style->FramePadding.x, 25.f))) {
			if (name == "") {
				g_Config.Save(g_Config.iSelConfig);
				g_Config.Load(g_Config.iSelConfig);
			}
			else {
				g_Config.Save(name);
			}
			name.clear();
		}
		ImGui::SameLine();
		if (ImGui::Button(XOR("Load"), ImVec2(vSize.x / 6 - style->WindowPadding.x - style->FramePadding.x, 25.f))) {
			g_Config.Load(g_Config.iSelConfig);
		}
		ImGui::SameLine();
		if (ImGui::Button(XOR("Delete"), ImVec2(vSize.x / 6 - style->WindowPadding.x - style->FramePadding.x, 25.f)))
			g_Config.Delete(g_Config.iSelConfig);
		ImGui::PushStyleColor(ImGuiCol_Text, g_Config.Status().error ? IM_COL32(255, 0, 0, 255) : IM_COL32(0, 255, 0, 255));
		ImGui::Text(g_Config.Status().msg.c_str());
		ImGui::PopStyleColor();

		if (g_PlayerList.bListOpened ? ImGui::Button(XOR("Close Playerlist"), ImVec2(-1.f, 0.f)) : ImGui::Button(XOR("Open Playerlist"), ImVec2(-1.f, 0.f)))
			g_PlayerList.bListOpened = !g_PlayerList.bListOpened;
		ImGui::EndChild();

		for (size_t i = 0; i < g_Config.configs.size(); i++) {
			delete[] CConfigArr[i];
		}
		delete[] CConfigArr;
	}

		  break;
	}
}

void Menu::Init() {
	// init imgui
	ImGui::CreateContext();
	ImPlot::CreateContext();
	
	ImGuiIO& io = ImGui::GetIO();

	io.MouseDrawCursor = true;

	ImGui_ImplWin32_Init(g_DirectX.window);
	ImGui_ImplDX9_Init(g_DirectX.pDevice);

	bInitialized = true;
	std::cout << XOR("[ RAYBOT ] Successfully Initialized ImGui/ImPlot\n");
}