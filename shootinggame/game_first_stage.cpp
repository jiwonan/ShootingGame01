#include "game_first_stage.h"
#include "global.h"

GameFirstStage::GameFirstStage()
{

}
void GameFirstStage::Update()
{

}
void GameFirstStage::Render()
{
    TextureElement* background = textureManager.GetTexture(GAME_BACKGROUND);

    // Rendering of scene objects can happen here
    background->sprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.bottom = 480;
    srcRect.right = 640;

    D3DXVECTOR3 pos(0, 0, 0);

    background->sprite->Draw(background->texture, &srcRect, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
    background->sprite->End();
}