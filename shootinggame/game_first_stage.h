#pragma once

#include "stage.h"
#include "game_background.h"

class GameFirstStage : public Stage
{
public:
	GameFirstStage();
	void Update() override;
	void Render() override;

	GameBackground background;
};