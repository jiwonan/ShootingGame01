#pragma once

#include "Bullet.h"

class BossBulletA : public Bullet
{
public:
	BossBulletA(float x, float y, float vx, float vy);
	void Update();
	void Render();
	bool IsDead();
	float GetRadius();
	D3DXVECTOR2 GetPosition();
	void Hit();

	float posX;
	float posY;

	float velX;
	float velY;

	float speed;

	bool isDead;
};