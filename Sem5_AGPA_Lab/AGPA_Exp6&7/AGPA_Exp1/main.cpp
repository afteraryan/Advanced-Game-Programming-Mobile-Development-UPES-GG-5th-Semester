#include<gl/glut.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<iostream>
#include<time.h>
using namespace std;
int WindowWidth = 1000, WindowHeight = 1000;

GLfloat xOffset=0, yOffset;


void keypress(unsigned char key, int x, int y)
{
	if (key == 'a')
	{

		xOffset--;
	}

	if (key == 'd')
	{
		xOffset++;
	}

	if (key == 'w')
	{
		yOffset++;
	}

	if (key == 's')
	{
		yOffset--;
	}
	
	glutPostRedisplay();

}

void init(void)
{
	gluOrtho2D(0, 100, 100, 0);
}

void DrawLine(GLfloat xStart, GLfloat yStart, GLfloat xEnd, GLfloat yEnd)
{
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(xStart, yStart);
	glVertex2f(xEnd, yEnd);
	glEnd();
}


class RectangleClass
{
public:
	struct Vertex
	{
		GLfloat x, y;
	};
	Vertex TL, BR;

	GLfloat top = 0, bottom = WindowHeight, left = WindowWidth, right = 0;
	

	void SetVertex(GLfloat Ox, GLfloat Oy, GLfloat Length, GLfloat Breadth)
	{

		TL.x = Ox;
		TL.y = Oy;
		BR.x = Ox+Length;
		BR.y = Oy+Breadth;
	}
	void Render()
	{
		DrawLine(TL.x, TL.y, TL.x, BR.y);
		DrawLine(TL.x, BR.y,BR.x,BR.y);
		DrawLine(BR.x, BR.y, BR.x,TL.y);
		DrawLine(BR.x, TL.y, TL.x, TL.y);
	}

	void Render(int Black)
	{
		DrawLine(TL.x, TL.y, TL.x, BR.y);
		DrawLine(TL.x, BR.y, BR.x, BR.y);
		DrawLine(BR.x, BR.y, BR.x, TL.y);
		DrawLine(BR.x, TL.y, TL.x, TL.y);
	}
};


RectangleClass R1, R2;

bool IsOverlapping()
{
	if (R1.TL.x == R1.BR.x || R1.TL.y == R1.BR.y || R2.BR.x == R2.TL.x || R2.TL.y == R2.BR.y)
		return false;
	if (R1.TL.x > R2.BR.x || R2.TL.x > R1.BR.x)
		return false;
	if (R1.BR.y > R2.TL.y || R2.BR.y > R1.TL.y)
		return false;

	return true;

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	R1.SetVertex(10, 10, 10, 10);
	//R2.SetVertex(50+xOffset, 30+yOffset, 60+xOffset, 20+yOffset);
	R1.Render();
	//R2.Render();

	if (IsOverlapping())
	{
		//Text
		glColor3f(1.0, 0, 0.0);
		glRasterPos2f(80, 80); //define position on the screen
		char* strName = (char*)"OVERLAPPING!!";
		for (int i = 0; i < (int)strlen(strName); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_8_BY_13, strName[i]);
		}
	}
	glutSwapBuffers();
}







int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);

	glutInitWindowSize(WindowWidth, WindowHeight);
	glutCreateWindow("Aryan Saxena: 500082431");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(&keypress);
	glutMainLoop();
	return 0;
}