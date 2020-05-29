#include "title_stage.h"
#include "global.h"

TitleStage::TitleStage()
{

}

void TitleStage::Update()
{

}

void TitleStage::Render()
{
	TextureElement* element = textureManager.GetTexture(TEX_TITLE_SCREEN);

    // Rendering of scene objects can happen here
    element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.bottom = 480;
    srcRect.right = 640;

    D3DXVECTOR3 pos(0, 0, 0);

    element->sprite->Draw(element->texture, &srcRect, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
    element->sprite->End();
}