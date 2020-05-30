#include "game_system.h"
#include "player_bullet_spread.h"

void GameSystem::GeneratePlayerBulletSpread(int x, int y)
{
	float speed = 8;

	int n = 5;
	for (int i = 0; i < 5; ++i)
	{
		float deltaAngle = (i * 8 + 70) * 3.141592f / 180.0f;

		float vx = cos(deltaAngle) * speed;
		float vy = -sin(deltaAngle) * speed;
		PlayerBulletSpread* newBullet = new PlayerBulletSpread(x, y, vx, vy);
		bullets.push_back(newBullet);
	}
}

void GameSystem::Update()
{
	for (auto iter = bullets.begin(); iter != bullets.end(); )
	{
		(*iter)->Update();
		if ((*iter)->IsDead())
		{
			iter = bullets.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}
void GameSystem::Render()
{
	for (int i = 0; i < bullets.size(); ++i)
	{
		bullets[i]->Render();
	}
}