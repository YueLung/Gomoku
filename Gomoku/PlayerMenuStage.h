#pragma once
#include "MenuStage.h"
class PlayerMenuStage :public MenuStage
{
public:
	PlayerMenuStage(Game* game);
	~PlayerMenuStage();

	void playerVsPlayerButtonFun();
	void computerVsPlayerButtonFun();

};

