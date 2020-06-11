#pragma once

#include <d3dx9math.h>

class Player
{
public:
	Player();
	void Update();
	void Render();
	D3DXVECTOR2 GetPosition();
	float GetRadius();

	void HitByEnemyBody(int damage);
	void HitByBossBullet(int damage);

	float playerX;
	float playerY;
	float speed;

	float hp;
	bool enableInvincible;
	float invincibleTime;
};