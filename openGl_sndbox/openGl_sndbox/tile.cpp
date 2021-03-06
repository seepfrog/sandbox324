#include "stdafx.h"
#include "GL\freeglut.h"
#include "tile.h"

namespace tile {

	int gridTile:: get_tile_x_position() { return tile_x_position; }
	int gridTile:: get_tile_y_position() { return tile_y_position; }

	void gridTile::set_tile_position(int x, int y) {
		tile_x_position = x;
		tile_y_position = y;
	}

	void gridTile::draw_tile(){

		int tile_size = get_tile_size();
		int x = get_tile_x_position();
		int y = get_tile_y_position();

		glPushMatrix();

		glLineWidth(3);
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_QUADS);
		glVertex3f(-tile_size + x, -tile_size + y, 1.0);
		glVertex3f( tile_size + x, -tile_size + y,  1.0);
		glVertex3f( tile_size + x,  tile_size + y,  1.0);
		glVertex3f(-tile_size + x,  tile_size + y,  1.0);
		glEnd();

		glLineWidth(1.0);
		glPopMatrix();
	}


} // namespace tile 

