#pragma once
#include "stdafx.h"

namespace tile {
	class gridTile {
	private:
		double tile_size = 0;
		int x_offset = 0;
		int y_offset = 0;

		int tile_x_position = 0;
		int tile_y_position = 0;

	public:
		int get_tile_size() { return tile_size; }

		int get_tile_x_position();
		int get_tile_y_position();

		void set_tile_position(int x, int y);

		gridTile(int size, int x, int y) {
			tile_size = size;
			x_offset = x;
			y_offset = y;

			tile_x_position = x_offset;
			tile_y_position = y_offset;
		}

		//現在位置にタイルを描画
		void draw_tile();

	};


} // namespace tile 
