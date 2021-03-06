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
void Draw_grid(int d, double x, double y, double h) {

	glPushMatrix();

	glDisable(GL_LIGHTING);

	glColor3f(0, 0, 0);
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

void idle(void)
{
	glutPostRedisplay();
}


void display(void)
{
	static int x = 25;
	static int y = 25;
	tile::gridTile tile1(20, x, y);

	glClear(GL_COLOR_BUFFER_BIT);
	Draw_grid(20, 500, 500, 1);

	tile1.draw_tile();
	tile1.set_tile_position(x, y);
	if (x < 500) {
		x += 1;
	}
	
	//y += 0;
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


void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			/* アニメーション開始 */
			glutIdleFunc(idle);
		}
		else {
			/* アニメーション停止 */
			glutIdleFunc(0);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			/* コマ送り (1ステップだけ進める) */
			glutPostRedisplay();
		}
		break;
	default:
		break;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'q':
	case 'Q':
	case '\033':  /* '\033' は ESC の ASCII コード */
		exit(0);
	default:
		break;
	}
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
		glutMouseFunc(mouse);
		glutKeyboardFunc(keyboard);
		init();
		glutMainLoop(); //*/
		return 0;
	}
	catch (...) {
		return 1;
	}
}

#include <chrono>

void chrono_test() {
	std::chrono::system_clock::time_point  start, now, end; // 型は auto で可
	double nowD;
	start = std::chrono::system_clock::now(); // 計測開始時間
	 // 処理
	for (int i = 0; i < 10000; i++) {
		now = std::chrono::system_clock::now();
		nowD = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
		std::cout << nowD << "hoge" << std::endl;
	}
	end = std::chrono::system_clock::now();  // 計測終了時間
	double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //処理に要した時間をミリ秒に変換
	std::cout << elapsed;
	getchar();
}

void test_daikei_up() {
	int  n = 100;
	auto start = std::chrono::system_clock::now();
	auto now = std::chrono::system_clock::now();
	double time = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();

	while (time < n) {

		now = std::chrono::system_clock::now();
		time = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
		std::cout << time << std::endl;
	}
	getchar();
}

void test_daikei_down() {
	int  n = 100;
	auto start = std::chrono::system_clock::now();
	auto now = std::chrono::system_clock::now();
	double time = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();

	while (time < n) {

		now = std::chrono::system_clock::now();
		time = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
		std::cout << 100 - time << std::endl;
	}
	getchar();
}


int main(int argc, char *argv[])
{
	//gl_main(argc, argv);
	//chrono_test();
	test_daikei_up();
	test_daikei_down();
	getchar();
	return 0;
}