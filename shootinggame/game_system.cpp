#include "game_system.h"
#include "player_bullet_spread.h"

void GameSystem::GeneratePlayerBulletSpread(int x, int y)
{
	float vx = 0;
	float vy = -10.0f;

	PlayerBulletSpread* newBullet = new PlayerBulletSpread(x, y, vx, vy);
	bullets.push_back(newBullet);
}

void GameSystem::Update()
{
	int a = 10;
	for (int i = 0; i < bullets.size(); ++i)
	{
		bullets[i]->Update();
	}
}
void GameSystem::Render()
{
	for (int i = 0; i < bullets.size(); ++i)
	{
		bullets[i]->Render();
	}
}