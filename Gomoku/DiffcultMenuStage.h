#pragma once
#include "MenuStage.h"

class DiffcultMenuStage :public MenuStage
{
public:
	DiffcultMenuStage(Game *game);
	~DiffcultMenuStage();

	void easyButtonFun();
	void mediumButtonFun();
	void hardButtonFun();
};

