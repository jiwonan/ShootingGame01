#pragma once

#include "animation_frame.h"
#include "sprite_effect.h"

#include <vector>
#include <windows.h>

using namespace std;

class EnemyExplosionA :public SpriteEffect
{
public:
	EnemyExplosionA(float x, float y);

	void Update() override;
	void Render() override;
	bool IsDead() override;

	float posX;
	float posY;
	bool isDead;

	RECT GetSourceRect();

	vector<AnimationFrame> frames;
	int frameIndex;
	float animTime;
};