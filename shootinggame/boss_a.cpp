#include "boss_a.h"
#include "global.h"

BossA::BossA()
{
	isDead = false;
	hp = 400;

	hitTimer = 0;
	floatingTimer = 0;

	const int centerX = WINDOW_WIDTH / 2;
	const int rangeX = 10;
	const int tempX = (rand() % rangeX) - (rangeX / 2);
	posX = centerX + tempX;
	posY = -50;

	velX = 0;
	velX = 0;
}

void BossA::Update()
{
	posY = cosf(floatingTimer * 3) * 5;
	floatingTimer += deltaTime;

}

void BossA::Render()
{
	TextureElement* bossA = textureManager.GetTexture(GAME_ENEMY_BOSS_A_BODY);

	// Rendering of scene objects can happen here
	bossA->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT srcRect;
	srcRect.left = 0;
	srcRect.top = 0;
	srcRect.bottom = 163;
	srcRect.right = 327;

	D3DXVECTOR3 pos(posX - 327 / 2, posY - 163 / 2, 0);

	if (hitTimer > 0)
	{
		bossA->sprite->Draw(bossA->texture, &srcRect, nullptr, &pos, D3DCOLOR_XRGB(255, 0, 0));
		hitTimer -= 1;
	}
	else
	{
		bossA->sprite->Draw(bossA->texture, &srcRect, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
	}
	bossA->sprite->End();
}

bool BossA::IsDead()
{
	return isDead;
}

float BossA::GetRadius()
{
	return 150.0f;
}

D3DXVECTOR2 BossA::GetPosition()
{
	return D3DXVECTOR2(posX, posY);
}

void BossA::Hit(float damage)
{
	if (!IsDead())
	{
		hitTimer = 2;
		hp -= damage;
		if (hp <= 0)
		{
			gameStat.gameScore += 1000;
			isDead = true;
		}
	}
}
