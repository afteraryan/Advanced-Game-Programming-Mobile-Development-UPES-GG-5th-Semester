#include<gl/glut.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<iostream>
#include<time.h>
using namespace std;
int WindowWidth = 1000, WindowHeight = 1000;


void init(void)
{
	gluOrtho2D(0, WindowWidth, 0, WindowHeight);
}

void DrawLine(GLfloat xStart, GLfloat yStart, GLfloat xEnd, GLfloat yEnd)
{
	glBegin(GL_LINES);
	glColor3f(1, 0, 1);
	glVertex2f(xStart, yStart);
	glVertex2f(xEnd, yEnd);
	glEnd();
}

void DrawPolygonHollow()
{
	//Inner
	DrawLine(571, 429, 500, 400);
	DrawLine(500, 400, 429, 429);
	DrawLine(429, 429, 400, 500);
	DrawLine(400, 500, 429, 571);
	DrawLine(429, 571, 500, 600);
	DrawLine(500, 600, 571, 571);
	DrawLine(571, 571, 600, 500);
	DrawLine(600, 500, 571, 429);
	//Middle
	DrawLine(641, 359, 500, 300);
	DrawLine(500, 300, 359, 359);
	DrawLine(359, 359, 300, 500);
	DrawLine(300, 500, 359, 641);
	DrawLine(359, 641, 500, 700);
	DrawLine(500, 700, 641, 641);
	DrawLine(641, 641, 700, 500);
	DrawLine(700, 500, 641, 359);
	//Outter
	DrawLine(712, 288, 500, 200);
	DrawLine(500, 200, 288, 288);
	DrawLine(288, 288, 200, 500);
	DrawLine(200, 500, 288, 712);
	DrawLine(288, 712, 500, 800);
	DrawLine(500, 800, 712, 712);
	DrawLine(712, 712, 800, 500);
	DrawLine(800, 500, 712, 288);
}

void DrawWeb()
{
	DrawPolygonHollow();
	DrawLine(0, 0, 1000, 1000);
	DrawLine(500, 0, 500,1000);
	DrawLine(1000, 0, 0, 1000);
	DrawLine(0, 500, 1000, 500);
}

void displayWeb(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	//Draw Function
	DrawWeb();
	glutSwapBuffers();
}

class RectangleClass
{
	
public:
	GLfloat Origin[2], Height, Width, Color[3];
	void Render()
	{
		glBegin(GL_POLYGON);
		RandowmColor();
		glColor3f(Color[0], Color[1], Color[2]);
		glVertex2f(Origin[0], Origin[1]);
		glVertex2f(Origin[0] + Width, Origin[1]);
		glVertex2f(Origin[0] + Width, Origin[1] + Height);
		glVertex2f(Origin[0], Origin[1] + Height);
		glEnd();
	}
	void RandowmColor()
	{
		Color[0] = (GLfloat)randZeroToOne();
		Color[1] = (GLfloat)randZeroToOne();
		Color[2] = (GLfloat)randZeroToOne();
	}
	double randZeroToOne()
	{
		return rand() / (RAND_MAX + 1.);
	}
};

void displayGrid(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	//Draw Function
	RectangleClass Rect[4][3];
	GLfloat localOrigin[2]={250,250}, localHeight = 100,localWidth = 200;
	for (int i = 0; i < 4; i++)
	{
		
		for (int j = 0; j < 3; j++)
		{
			Rect[i][j].Origin[0] = localOrigin[0];
			Rect[i][j].Origin[1] = localOrigin[1];
			Rect[i][j].Height = localHeight;
			Rect[i][j].Width = localWidth;
			Rect[i][j].Render();
			localOrigin[0] = localOrigin[0]+localWidth;
		}
		localOrigin[0] = 250;
		localOrigin[1] = localOrigin[1] + localHeight;
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
	glutDisplayFunc(displayGrid);
	glutMainLoop();
	return 0;
}