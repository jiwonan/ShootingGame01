#include "game_system.h"
#include "player_bullet_spread.h"
#include "enemy_a.h"
#include "global.h"

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

void GameSystem::GenerateEnemyA()
{
	Enemy* enemyA = new EnemyA();
	enemies.push_back(enemyA);
}

void GameSystem::Update()
{
	enemyATime += deltaTime;
	if (rand() % 100 < 5)
	{
		if (enemyATime > 0.1f)
		{
			GenerateEnemyA();

			enemyATime = 0;
		}
	}

	// 적 총알 업데이트
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

	// 적 업데이트
	for (auto iter = enemies.begin(); iter != enemies.end(); )
	{
		(*iter)->Update();
		if ((*iter)->IsDead())
		{
			iter = enemies.erase(iter);
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

	for (int i = 0; i < enemies.size(); ++i)
	{
		enemies[i]->Render();
	}
}