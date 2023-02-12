#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include<time.h> 
#include<string>  
using namespace std;

#define LBoundry -1
#define RBoundry 1
#define BBoundry -1
#define TBoundry 1
class Rect
{
protected:
	float x, y, h, w;
	float velocityX, velocityY;
	int collision = 0;
	bool isPointInsideRect(float a, float b)
	{
		if (a >= x && a <= x + w)
			if (b >= y && b <= y + h)
				return true;
		return false;
	}
	// float cr,cg,cb;
public:
	Rect(float X, float Y, float H, float W, float vx = 0, float vy = 0)
	{
		x = X;
		y = Y;
		h = H;
		w = W;
		velocityX = vx;
		velocityY = vy;
	}
	void setColor(float R, float G, float B)
	{
		glColor3f(R, G, B);
	}
	void setVelocity(float xx, float yy)
	{
		velocityX = xx;
		velocityY = yy;
	}
	int score = 0;


	int  getScore() {
		return score;
	}
	void addScore(int s) {
		score = score + s;
	}
	void display()
	{
		x += velocityX;
		y += velocityY;
		glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(x + w, y);
		glVertex2f(x + w, y + h);
		glVertex2f(x, y + h);
		glEnd();
	}

	bool isCollide(Rect r1)
	{
		if (isPointInsideRect(r1.x, r1.y) || isPointInsideRect(r1.x + r1.w, r1.y) || isPointInsideRect(r1.x + r1.w, r1.y + r1.h) || isPointInsideRect(r1.x, r1.y + r1.h))
		{
			collision = 1;

		}
		else {

			collision = 0;
		}
		return collision;
	}

};

class controlRect : public Rect
{
	float speed = .03;
public:
	controlRect(float X, float Y, float H, float W, float vx = 0, float vy = 0) : Rect(X, Y, H, W, vx, vy)
	{

	}
	void display()
	{
		if (x <= LBoundry)
			setVelocity(0.001, 0);
		if (x + w >= RBoundry)
			setVelocity(-0.001, 0);
		if (y <= BBoundry)
			setVelocity(0, 0.001);
		if (y + h >= TBoundry)
			setVelocity(0, -0.001);
		Rect::display();
	}

	void MoveRight()
	{

		setVelocity(speed, 0);
	}
	void MoveLeft()
	{
		setVelocity(-speed, 0);
	}
	void MoveUp()
	{
		setVelocity(0, speed);
	}
	void MoveDown()
	{
		setVelocity(0, -speed);
	}
	void stop()
	{
		setVelocity(0, 0);
	}
};


class BoundingRect : public Rect
{
public:
	void display()
	{

		glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(x + w, y);
		glVertex2f(x + w, y + h);
		glVertex2f(x, y + h);
		glEnd();
	}




	BoundingRect(float X, float Y, float H, float W, float vx = 0, float vy = 0) : Rect(X, Y, H, W, vx, vy)
	{

	}
};





BoundingRect r1 = BoundingRect(-0.1, 0, 0.25, 0.25, 0.01, .02);
controlRect pc = controlRect(-0.25, -0.5, 0.20, 0.20, 0, 0);



void timeOut(int a)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timeOut, 0);
}
void init()
{
	glViewport(0, 0, 500, 500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(LBoundry, RBoundry, BBoundry, TBoundry);
}

void keypress(unsigned char key, int x, int y)
{
	if (key == 'a')
	{

		pc.MoveLeft();
	}

	if (key == 'd')
	{
		pc.MoveRight();
	}

	if (key == 'w')
	{
		pc.MoveUp();
	}

	if (key == 's')
	{
		pc.MoveDown();
	}

}
void keyUpFunction(unsigned char key, int x, int y)
{
	pc.stop();
}
void renderBitmapString(float x, float y, void* font, const char* string)
{
	const char* c;
	glRasterPos3f(x, y, 0);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}
void display()
{


	glClear(GL_COLOR_BUFFER_BIT);

	r1.setColor(0.2, 0.9, 0.9);
	r1.display();
	pc.setColor(1.0, 1.0, 0);
	pc.display();

	if (pc.isCollide(r1)) {
		pc.setColor(0, 1.0, 0.0);
		renderBitmapString(-0.25, 0.90, GLUT_BITMAP_TIMES_ROMAN_24, "Collision Detected");

	}


	glColor3f(1.0f, 0.0f, 0.0f);



	glRasterPos2f(0, 0);


	glFlush();
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	int mode = GLUT_RGB | GLUT_SINGLE;
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(mode);
	glutCreateWindow("GLUT Test");
	init();
	glutDisplayFunc(&display);
	glutKeyboardFunc(&keypress);
	glutKeyboardUpFunc(&keyUpFunction);
	glutTimerFunc(1000 / 60, timeOut, 0);
	glutMainLoop();

	return EXIT_SUCCESS;
}