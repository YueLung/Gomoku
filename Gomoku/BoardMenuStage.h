#pragma once
#include "MenuStage.h"

class BoardMenuStage :public MenuStage
{
public:
	BoardMenuStage(Game* game);
	~BoardMenuStage();

	void fiveXfiveButtonFun();
	void tenXtenButtonFun();
	void fifteenXfifteenButtonFun();
};

