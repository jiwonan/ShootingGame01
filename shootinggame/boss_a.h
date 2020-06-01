#pragma once

#include "enemy.h"

class BossA : public Enemy
{
public:

	void Update() = 0;
	void Render() = 0;
	bool IsDead() = 0;
	float GetRadius() = 0;
	D3DXVECTOR2 GetPosition() = 0;
	void Hit(float damage) = 0;

	int hp;

	bool isDead;

	float posX;
	float posY;
	float velX;
	float velY;

};