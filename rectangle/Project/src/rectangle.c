#include <stdlib.h>
#include <gl/glut.h>

/* globals */
float xm, ym, xmm, ymm;
float width = 500, height = 500;
int first = 0;

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		xm = x / width;
		ym = (height - y) / height;
		glColor3f(0.0, 0.0, 1.0);
		glLogicOp(GL_XOR);
		first = 0;
	}
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		glRectf(xm, ym, xmm, ymm);
		glFlush();
		glColor3f(0.0, 1.0, 0.0);
		xmm = x / width;
		ymm = (height - y) / height;
		glLogicOp(GL_COPY);
		glRectf(xm, ym, xmm, ymm);
		glFlush();
	}
}

/* reshaping routine called whenever window is resized or moved */
void myReshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//* adjust viewport and clear */
	glViewport(0, 0, w, h);

	//* set global size for use by drawing routine */
	width = w; height = h;
}

void move(int x, int y)
{
	if (first == 1)
	{
		glRectf(xm, ym, xmm, ymm);
		glFlush();
	}

	xmm = x / width;
	ymm = (height - y) / height;
	glRectf(xm, ym, xmm, ymm);
	glFlush();

	first = 1;
}

void myinit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glLineWidth(3.0);
}

/* display callback required by GLUT */
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
	glutCreateWindow("Rectangle Rubberband");
	myinit();
	glEnable(GL_COLOR_LOGIC_OP);
	glutReshapeFunc(myReshape);
	glutMouseFunc(mouse);
	glutMotionFunc(move);
	glutDisplayFunc(display);

	glutMainLoop();
}
