#pragma once
#include "stdafx.h"

namespace tile {
	class Tile_Spec {
	private:
		static const int TILE_SIZE = 350;//天板の大きさ
		static const int WHEEL_SIZE = 70;//動輪の直径
	public:
		//コンストラクタ
		Tile_Spec() {}

		int get_tile_size();
		int get_wheel_size();


	};

	class Draw_tile {
		public:
			void draw_tile(int x ,int y);
	};

} // namespace tile 
