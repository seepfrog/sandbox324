#include "stdafx.h"
#include "GL\freeglut.h"
#include "tile.h"

namespace tile {

	void Draw_tile::draw_tile(int x, int y){

		int tile_size = 20;

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

