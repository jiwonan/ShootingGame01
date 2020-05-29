#include "Player.h"
#include "global.h"

Player::Player()
{
    PlayerX = WINDOW_WIDTH / 2;
    PlayerY = WINDOW_HEIGHT * 0.8f;
    speed = 1;
}

void Player::Update()
{
    if (inputManager.keyBuffer[VK_LEFT] == 1)
        PlayerX -= speed;

    if (inputManager.keyBuffer[VK_RIGHT] == 1)
        PlayerX += speed;

    if (inputManager.keyBuffer[VK_UP] == 1)
        PlayerY -= speed;

    if (inputManager.keyBuffer[VK_DOWN] == 1)
        PlayerY += speed;
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

    D3DXVECTOR3 pos(PlayerX - 16, PlayerY - 24, 0);
    player->sprite->Draw(player->texture, &srcRect, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));

    player->sprite->End();
}