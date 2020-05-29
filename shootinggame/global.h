#pragma once

#include <d3d9.h>
#include <D3dx9core.h>
#include "texture_manager.h"
#include "input_manager.h"
#include "stage_manager.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

#define TEX_TITLE_SCREEN 1000

extern LPDIRECT3D9 g_pD3D;
extern LPDIRECT3DDEVICE9 g_pd3dDevice;

// all the managers
extern TextureManager textureManager;
extern InputManager inputManager;
extern StageManager stageManager;