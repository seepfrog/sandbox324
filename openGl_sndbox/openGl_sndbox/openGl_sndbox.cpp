// openGl_sndbox.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "GL/freeglut.h"

#include "tile.h"

/*
*グリッド描画
*d　分割数
*x,y　グリッド全体の横縦
*h　グリッドの高さ
*/
void Draw_grid(int d, double x, double y, double h ) {

	glPushMatrix();

	glDisable(GL_LIGHTING);

	glColor3f(0,0,0);
	glLineWidth(6.0);
	glBegin(GL_LINE_LOOP);
	glVertex3d(-x, y, h);
	glVertex3d(x, y, h);
	glVertex3d(x, -y, h);
	glVertex3d(-x, -y, h);
	glEnd();
	glLineWidth(3.0);

	// x方向
	float x0, x1, y0, y1;
	float deltaX, deltaY;

	x0 = -x; x1 = -x;
	y0 = -y; y1 = y;
	deltaX = (2 * x) / d;

	for (int i = 0; i < d; ++i) {
		x0 = x0 + deltaX;
		glBegin(GL_LINES);
		glVertex3f(x0, y0, h);
		glVertex3f(x0, y1, h);
		glEnd();
	}

	// y方向
	x0 = -x; x1 = x;
	deltaY = (2 * y) / d;

	for (int i = 0; i < d; ++i) {
		y0 = y0 + deltaY;
		glBegin(GL_LINES);
		glVertex3f(x0, y0, h);
		glVertex3f(x1, y0, h);
		glEnd();
	}

	glLineWidth(1.0);
	glPopMatrix();
}



void display(void)
{
	tile::Draw_tile d;
	glClear(GL_COLOR_BUFFER_BIT);
	Draw_grid(20,500,500,1);
	d.draw_tile(25,25);
	glFlush();
}

void resize(int w, int h)
{
	/* ウィンドウ全体をビューポートにする */
	glViewport(0, 0, w, h);

	/* 変換行列の初期化 */
	glLoadIdentity();

	/* スクリーン上の表示領域をビューポートの大きさに比例させる */
	glOrtho(-w / 2.0, w / 2.0, -h / 2.0, h / 2.0, -1.0, 1.0);
}


void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

}

int gl_main(int argc, char *argv[]) {
	try {
		glutInitWindowPosition(500, 200);
		glutInitWindowSize(500, 500);
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGBA);
		glutCreateWindow(argv[0]);
		glutDisplayFunc(display);
		glutReshapeFunc(resize);
		init();
		glutMainLoop(); //*/
		return 0;
	}
	catch(...){
		return 1;
	}
}


int main(int argc, char *argv[])
{
	gl_main(argc, argv);
	return 0;
}