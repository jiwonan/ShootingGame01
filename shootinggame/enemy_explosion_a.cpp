#include "enemy_explosion_a.h"
#include "global.h"

EnemyExplosionA::EnemyExplosionA(float x, float y)
{
	posX = x;
	posY = y;
	isDead = false;

	for (int i = 0; i < 5; ++i)
	{
		int x = i * 64;
		int y = 0;
		int width = 64;
		int height = 64;

		AnimationFrame newFrame;

		newFrame.x = x;
		newFrame.y = y;
		newFrame.width = width;
		newFrame.height = height;
		newFrame.time = 0.1f;

		frames.push_back(newFrame);
	}

	frameIndex = 0;
	animTime = 0;
}

void EnemyExplosionA::Update()
{
	animTime += deltaTime;
	if (animTime > frames[frameIndex].time)
	{
		frameIndex++;
		animTime = 0;

		if (frameIndex >= frames.size())
		{
			frameIndex = frames.size() - 1;
			isDead = true;
		}
	}
}

void EnemyExplosionA::Render()
{
	TextureElement* explosionA = textureManager.GetTexture(GAME_ENEMY_EXPLOSION_A);

	// Rendering of scene objects can happen here
	explosionA->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT srcRect = GetSourceRect();

	D3DXVECTOR3 pos(posX - 32, posY - 32, 0);
	explosionA->sprite->Draw(explosionA->texture, &srcRect, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
	explosionA->sprite->End();
}

bool EnemyExplosionA::IsDead()
{
	return isDead;
}

RECT EnemyExplosionA::GetSourceRect()
{
	RECT srcRect;

	srcRect.left = frames[frameIndex].x;
	srcRect.top = frames[frameIndex].y;
	srcRect.right = frames[frameIndex].x + frames[frameIndex].width;
	srcRect.bottom = frames[frameIndex].y + frames[frameIndex].height;

	return srcRect;
}