#pragma once

namespace GameDef {

	namespace Board {
		const int BoardWidth  = 1000;
		const int BoardHeight = 800;
		
		const float LineThickness = 10.0f;

	}

	enum BoardGridEnum { FiveXFive, TenXTen, FifteenXFifteen };
	enum DifficultEnum { Easy, Medium, Hard };
	enum PlayerTypeEnum { PlayerVsPlayer, ComputerVsPlayer };

	//namespace Button {
	//	enum Type{
	//		PlayerVsPlayer, PlayerVsComputer
	//	};
	//}

	enum StageEnum {
		PlayerMenu, BoardMenu, DiffcultMenu, CheckBoard
	};
}


