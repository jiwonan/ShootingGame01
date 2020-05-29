#include "stage_manager.h"
#include "title_stage.h"

void StageManager::MakeTitleStage()
{

	if (currentStage != nullptr)
	{
		delete currentStage;
	}

	TitleStage* stage = new TitleStage();
	currentStage = stage;
}

void StageManager::Update()
{
	currentStage->Update();
}

void StageManager::Render()
{
	currentStage->Render();
}