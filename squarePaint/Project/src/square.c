/* program illustrates the use of the GLUT library for interfacing
with a window system */

/* The program opens a window, clears it to black, then draws a
box at the location of the mouse each time the left button is
clicked. The right button exits the program. The program also
reacts correctly when the window is moved or resized by clearing
the new window to black.*/

#include <stdlib.h>
#include <stdio.h>
#include <gl/glut.h>

/* globals */
GLsizei wh = 500, ww = 500; /* initial window size */
GLfloat size = 3.0;   /* half side length of square */

void drawSquare(int x, int y)
{
	y = wh - y;
	glColor3ub((char)rand() % 256, (char)rand() % 256, (char)rand() % 256);
	glBegin(GL_POLYGON);
	glVertex2f(x + size, y + size);
	glVertex2f(x - size, y + size);
	glVertex2f(x - size, y - size);
	glVertex2f(x + size, y - size);
	glEnd();
	glFlush();
}

/* reshaping routine called whenever window is resized or moved */
void myReshape(GLsizei w, GLsizei h)
{
	/* adjust clipping box */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, (GLdouble)w, 0.0, (GLdouble)h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//* adjust viewport and clear */
	glViewport(0, 0, w, h);

	//* set global size for use by drawing routine */
	ww = w;
	wh = h;
	printf("%d ", ww);
	printf("%d \n", wh);
}

void myinit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glViewport(0, 0, ww, wh);

	/* Pick 2D clipping window to match
	size of screen window. This choice avoids having to scale object
	coordinates each time window is resized. */

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, (GLdouble)ww, 0.0, (GLdouble)wh, -1.0, 1.0);
}

void mouse(int x, int y)
{
		//printf("%d %d\n", x, y);
		drawSquare(x, y);
}

/* display callback required by GLUT */
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(ww, wh);
	glutCreateWindow("square");
	myinit();
	glutReshapeFunc(myReshape);
	glutMotionFunc(mouse);
	glutDisplayFunc(display);

	glutMainLoop();
}
