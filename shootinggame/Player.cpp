#include "Player.h"
#include "global.h"

Player::Player()
{
    playerX = WINDOW_WIDTH / 2;
    playerY = WINDOW_HEIGHT * 0.8f;
    speed = 200;
}

void Player::Update()
{
    if (inputManager.keyBuffer[VK_LEFT] == 1)
        playerX -= speed * deltaTime;

    if (inputManager.keyBuffer[VK_RIGHT] == 1)
        playerX += speed * deltaTime;

    if (inputManager.keyBuffer[VK_UP] == 1)
        playerY -= speed * deltaTime;

    if (inputManager.keyBuffer[VK_DOWN] == 1)
        playerY += speed * deltaTime;

    if (playerX < 0)
        playerX = 0;

    if (playerY < 0)
        playerY = 0;

    if (playerX > WINDOW_WIDTH)
        playerX = WINDOW_WIDTH;

    if (playerY > WINDOW_HEIGHT)
        playerY = WINDOW_HEIGHT;

    if (inputManager.prevKeyBuffer['Z'] == 1 &&
        inputManager.keyBuffer['Z'] == 0)
    {
        gameSystem.GeneratePlayerBulletSpread(playerX, playerY - 30);
    }
}

void Player::Render()
{
    TextureElement* player = textureManager.GetTexture(GAME_PLAYER_BODY);

    // Rendering of scene objects can happen here
    player->sprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.bottom = 48;
    srcRect.right = 31;

    D3DXVECTOR3 pos(playerX - 16, playerY - 24, 0);
    player->sprite->Draw(player->texture, &srcRect, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));

    player->sprite->End();
}