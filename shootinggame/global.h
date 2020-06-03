#pragma once

#include <d3d9.h>
#include <D3dx9core.h>
#include "texture_manager.h"
#include "input_manager.h"
#include "stage_manager.h"
#include "game_system.h"
#include "game_stat.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

#define TEX_TITLE_SCREEN 1000

#define GAME_BACKGROUND 2000
#define GAME_PLAYER_BODY 2001
#define GAME_PLAYER_BULLET_1 2002

#define GAME_ENEMY_A_BODY 2003;
#define GAME_ENEMY_B_BODY 2004;

#define GAME_ENEMY_EXPLOSION_A 2005;

#define GAME_ENEMY_BOSS_A_BODY 2006

extern LPDIRECT3D9 g_pD3D;
extern LPDIRECT3DDEVICE9 g_pd3dDevice;

extern float deltaTime;

// all the managers
extern TextureManager textureManager;
extern InputManager inputManager;
extern StageManager stageManager;
extern GameSystem gameSystem;
extern GameStat gameStat;