#include "game_system.h"
#include "player_bullet_spread.h"
#include "enemy_a.h"
#include "global.h"
#include "math_util.h"
#include "Player.h"
#include "enemy_explosion_a.h"


GameSystem::GameSystem()
{
	gameStat.gameScore = 0;
}

void GameSystem::ClearAll()
{
	bullets.clear();
	enemies.clear();
	effects.clear();
}

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

void GameSystem::GenerateEnemyExplosionA(float x, float y)
{
	EnemyExplosionA* newEffect = new EnemyExplosionA(x, y);
	effects.push_back(newEffect);
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

	// 총알 업데이트
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
	
	// 적과 플레이어 총알 충돌 체크
	for (auto iter = bullets.begin(); iter != bullets.end(); )
	{
		for (int enemyIndex = 0; enemyIndex < enemies.size(); enemyIndex++)
		{
			Enemy* currentEnemy = enemies[enemyIndex];
			if (!currentEnemy->IsDead())
			{
				D3DXVECTOR2 enemyPos = currentEnemy->GetPosition();
				float enemyR = currentEnemy->GetRadius();

				D3DXVECTOR2 bulletPos = (*iter)->GetPosition();
				float bulletR = (*iter)->GetRadius();

				bool Result = isCircleCollided(bulletPos.x, bulletPos.y, bulletR,
					enemyPos.x, enemyPos.y, enemyR);

				if (Result)
				{
					(*iter)->Hit();
					currentEnemy->Hit(1);
					break;
				}
			}
		}
		iter++;
	}
	
	// 적 비행기와 플레이어 충돌 체크
	for (auto iter = enemies.begin(); iter != enemies.end(); )
	{
		Enemy* currentEnemy = (*iter);

		if (!currentEnemy->IsDead() && !player->enableInvincible)
		{
			D3DXVECTOR2 playerPos = player->GetPosition();
			float playerR = player->GetRadius();

			D3DXVECTOR2 enemyPos = currentEnemy->GetPosition();
			float enemyR = currentEnemy->GetRadius();

			bool Result = isCircleCollided(playerPos.x, playerPos.y,playerR,
				enemyPos.x, enemyPos.y, enemyR);

			if (Result)
			{
				player->HitByEnemyBody(30);
				currentEnemy->Hit(9999);
				break;
			}
		}

		iter++;
	}

	for (auto iter = effects.begin(); iter != effects.end(); )
	{
		(*iter)->Update();

		if ((*iter)->IsDead())
		{
			iter = effects.erase(iter);
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
	for (int i = 0; i < effects.size(); ++i)
	{
		effects[i]->Render();
	}
}