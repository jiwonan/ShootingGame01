#pragma once

#include <vector>

using namespace std;

class Bullet;
class Enemy;
class Player;
class SpriteEffect;
class GameStat;

class GameSystem
{
public:
	Player* player;
	vector<Bullet*> bullets;
	vector<Bullet*> enemyBullets;
	vector<Enemy*> enemies;
	vector<SpriteEffect*> effects;

	GameSystem();
	void ClearAll();

	void GameStartLevelOne();

	void GeneratePlayerBulletSpread(int x, int y);
	void GenerateEnemyA();
	void GenerateEnemyExplosionA(float x, float y);
	void GenerateEnemyBossA();
	void GenerateBossABullet(float x, float y, float vx, float vy);

	void Update();
	void Render();

	float enemyATime;
};