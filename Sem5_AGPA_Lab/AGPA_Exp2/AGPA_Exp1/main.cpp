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
	glColor3f(1, 1, 1);
	glVertex2f(xStart, yStart);
	glVertex2f(xEnd, yEnd);
	glEnd();
}


class RectangleClass
{
	struct Vertex
	{
		GLfloat x, y;
	}v[4];

	GLfloat top = 0, bottom = WindowHeight, left = WindowWidth, right = 0;
	
public:

	RectangleClass(GLfloat v0x, GLfloat v0y, GLfloat v1x, GLfloat v1y, GLfloat v2x, GLfloat v2y, GLfloat v3x, GLfloat v3y)
	{
		v[0].x = v0x; v[0].y = v0y;
		v[1].x = v1x; v[1].y = v1y;
		v[2].x = v2x; v[2].y = v2y;
		v[3].x = v3x; v[3].y = v3y;
		Extremes();
	}

	void InputVertex()
	{
		for (int i = 0; i < 4; i++)
		{
			cout << "Enter x,y coordinates for vertex " << i + 1 << ": ";
			cin >> v[i].x >> v[i].y;
		}
		Extremes();
		
	}

	void Extremes()
	{
		for (int i = 0; i < 4; i++)
		{
			if (top <= v[i].y)
				top = v[i].y;
			if (bottom >= v[i].y)
				bottom = v[i].y;
			if (right <= v[i].x)
				right = v[i].x;
			if (left >= v[i].x)
				left = v[i].x;
		}
		cout << "Top: " << top << "\t" << "Bottom: " << bottom << "\t" << "Right: " << right << "\t" << "Left: " << left << endl;
	}
	
	void Render()
	{
		DrawLine(v[0].x, v[0].y, v[1].x, v[1].y);
		DrawLine(v[1].x, v[1].y, v[2].x, v[2].y);
		DrawLine(v[2].x, v[2].y, v[3].x, v[3].y);
		DrawLine(v[3].x, v[3].y, v[0].x, v[0].y);
	}
};




void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	RectangleClass Rec(100, 900, 600, 900, 600, 100, 100, 100);
	Rec.Render();
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
	glutMainLoop();
	return 0;
}