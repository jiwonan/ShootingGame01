#pragma once

#include <d3d9.h>
#include <D3dx9core.h>
#include "texture_manager.h"
#include "input_manager.h"

extern LPDIRECT3D9 g_pD3D;
extern LPDIRECT3DDEVICE9 g_pd3dDevice;

// all the managers
extern TextureManager textureManager;
extern InputManager inputManager;