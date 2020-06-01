#pragma once

#include "enemy.h"

class BossA : public Enemy
{
public:
	BossA();
	void Update();
	void Render();
	bool IsDead();
	float GetRadius();
	D3DXVECTOR2 GetPosition();
	void Hit(float damage);

	int hp;

	bool isDead;

	float posX;
	float posY;
	float velX;
	float velY;

	float hitTimer;
	float floatingTimer;

};