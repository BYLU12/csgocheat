#pragma once
#include "includes.h"

class DirectX {
public:
	inline static LPDIRECT3DDEVICE9 pDevice = nullptr;
	int iWindowHeight = 0, iWindowWidth = 0;
	HWND window;

public:
	bool GetD3D9Device(void** pTable, size_t size);
	HWND GetProcessWindow();
};

// extern vars and class for hooking and drawing
extern DirectX g_DirectX;