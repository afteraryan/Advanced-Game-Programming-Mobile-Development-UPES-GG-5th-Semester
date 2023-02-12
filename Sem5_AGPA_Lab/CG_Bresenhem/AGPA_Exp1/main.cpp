#include <stdlib.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>

using namespace std;

int ScreenWidth = 500, ScreenHeight = 500;
int x1, y11, x2, y2;

void PrintSlope(float Slope)
{
	//Text
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f(20, 450); //define position on the screen
	char* strName = (char*)"Slope= ";
	for (int i = 0; i < (int)strlen(strName); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, strName[i]);
	}

	glRasterPos2f(80, 450);
	char buffer[10];
	int ret = snprintf(buffer, sizeof buffer, "%.2f", Slope);
	char* strSlope = (char*)buffer;
	for (int i = 0; i < (int)strlen(strSlope); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, strSlope[i]);
	}
	cout << buffer;
}

void mouseDown(int button, int state, int mousex, int mousey)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		x1 = mousex; y11 = ScreenHeight - mousey;
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		x2 = mousex; y2 = ScreenHeight - mousey;
		glutPostRedisplay();
	}
}

void DrawPoint(int x, int y, float Slope)
{
	glBegin(GL_POINTS);
	//if(Slope)
	glVertex2i(x, y);
	glEnd();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0, ScreenWidth, 0, ScreenHeight);
}

void Bres(int x1, int y11, int x2, int y2)
{
	int x = x1, y = y11;
	int dx = x2 - x1;
	int dy = y2 - y11;
	float Slope = (float)dy / dx;
	//Slope<1
	if (abs(dx) > abs(dy))
	{
		glColor3f(0.0, 0.0, 1.0); //Slope less than 1, Colour = Blue
		DrawPoint(x, y, Slope);
		int P = 2 * abs(dy) - abs(dx);
		for (int i = 0; i < abs(dx); i++)
		{
			x++;
			if (P < 0)
				P = P + 2 * abs(dy);
			else
			{
				P = P + 2 * abs(dy) - 2 * abs(dx);
				y++;
			}
			DrawPoint(x, y, Slope);
		}
	}

	if (abs(dx) > abs(dy) && dx/dy<0)
	{
		glColor3f(0.0, 0.0, 1.0); //Slope less than 1, Colour = Blue
		DrawPoint(x, y, Slope);
		int P = 2 * abs(dy) - abs(dx);
		for (int i = 0; i < abs(dx); i++)
		{
			x--;
			if (P < 0)
				P = P + 2 * abs(dy);
			else
			{
				P = P + 2 * abs(dy) - 2 * abs(dx);
				y--;
			}
			DrawPoint(x, y, Slope);
		}
	}


	//Slope>=1
	else
	{
		glColor3f(1.0, 0.0, 0.0); //Slope greater than equal to 1, Colour = Red
		DrawPoint(x, y, Slope);
		int P = (2 * abs(dx)) - abs(dy);
		for (int i = 0; i < abs(dy); i++)
			{
			y++;
			if (P < 0)
			P = P + (2 * abs(dx));
			else
			{
			P = P + (2 * abs(dx)) - (2 * abs(dy));
			x++;
			}
			DrawPoint(x, y, Slope);
			}
	}
	PrintSlope((float)dy / dx);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	Bres(x1, y11, x2, y2);
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(ScreenWidth, ScreenHeight);
	glutCreateWindow("Avishkar Mahendra Kadam: 500082413");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouseDown);
	glutMainLoop();
	return 0;
}

