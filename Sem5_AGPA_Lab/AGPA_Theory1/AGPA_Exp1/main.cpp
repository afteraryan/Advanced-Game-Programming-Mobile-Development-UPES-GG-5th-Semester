#include <stdlib.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>

#define LBoundry -1
#define RBoundry 1
#define BBoundry -1
#define TBoundry 1
int score = 0;
bool canUpdate = true;

void PrintScore()
{
	//Text
	glColor3f(0.0, 1.0, 1.0);
	glRasterPos2f(-0.8, 0.5); //define position on the screen
	char* strName = (char*)"Score= ";
	for (int i = 0; i < (int)strlen(strName); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, strName[i]);
	}

	glRasterPos2f(-0.6, 0.5);
	char buffer[10];
	int ret = snprintf(buffer, sizeof buffer, "%.0f", (float)score);
	char* strScore = (char*)buffer;
	for (int i = 0; i < (int)strlen(strScore); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, strScore[i]);
	}
}

void TimerController()
{
	float timeElapsed = glutGet(GLUT_ELAPSED_TIME);
	timeElapsed /= 1000;
	float timeRemaining = 60 - timeElapsed;
	if (timeRemaining <= 0)
	{
		_Exit(10);
	}


	//Text
	glColor3f(0.0, 1.0, 1.0);
	glRasterPos2f(0.6, 0.5); //define position on the screen
	char* strName = (char*)"Timer: ";
	for (int i = 0; i < (int)strlen(strName); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, strName[i]);
	}

	glRasterPos2f(0.8, 0.5);
	char buffer[10];
	int ret = snprintf(buffer, sizeof buffer, "%.0f", (float)timeRemaining);
	char* strTimer = (char*)buffer;
	for (int i = 0; i < (int)strlen(strTimer); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, strTimer[i]);
	}
}



class Rect
{
protected:
	float x, y, h, w;
	float velocityX, velocityY;
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
			if (canUpdate == true) {

				score++;
				canUpdate = false;
			}

			return true;
		}
		else
			return false;
	}

};

class mainRect : public Rect
{
	float speed = .03;
public:
	mainRect(float X, float Y, float H, float W, float vx = 0, float vy = 0) : Rect(X, Y, H, W, vx, vy)
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
		int flag = touchingBoundry();
		if (flag)
		{
			if (flag == -1)
				velocityY = -velocityY;
			if (flag == 1)
				velocityX = -velocityX;
		}

		Rect::display();
	}
	void random(float& X, float& Y) {
		srand(time(NULL));
		int mx = 1;
		int my = 1;
		int mi = -1;
		X = mi + (rand() % (mx - mi));
		Y = mi + (rand() % (my - mi));
	}
	int touchingBoundry()
	{
		if (x < LBoundry || x + w > RBoundry)
			return 1;
		if (y < BBoundry || y + h > TBoundry)
			return -1;
		return 0;
	}
	BoundingRect(float X, float Y, float H, float W, float vx = 0, float vy = 0) : Rect(X, Y, H, W, vx, vy)
	{

	}

	~BoundingRect() {


	}
};

mainRect pc = mainRect(-0.0, -0.0, 0.20, 0.20, 0, 0);
BoundingRect r1 = BoundingRect(-0.5, -0.5, 0.15, 0.15, 0.01, .02);

void timeOut(int a)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 100, timeOut, 0);
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
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	PrintScore();
	TimerController();

	r1.setColor(1.0, 0, 0);
	if (!pc.isCollide(r1)) {
		canUpdate = true;
		r1.display();

	}
	else {

	}
	glColor3f(0.0f, 1.0f, 0.0f);

	pc.display();
	glFlush();
	glRasterPos2f(-0.95, 0.85);

	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, score);

	glFlush();
}


/* Main method */
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
	glutTimerFunc(1000 / 100, timeOut, 0);
	glutMainLoop();

	return EXIT_SUCCESS;
}