#include "stdafx.h"
#include <math.h>
#define GL_PI 3.1415f
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

void RenderScene(void)
{
	GLfloat x, y, z, angle;
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(0.0f, 0.0f);
	for (angle = 0.0f; angle < (4.0f*GL_PI); angle += (GL_PI / 4.5f))
	{
		x = 50.0f*sin(angle);
		y = 50.0f*cos(angle);

		glColor3f(1.0f, 0.0f, 0.0f);

		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}

void SetupRC(void)
{
	glClearColor(0.6f, 0.4f, 0.12f, 1.0f);
}

void ChangeSize(int w, int h)
{
	GLfloat aspectRatio;

	if (h == 0)   h = 1;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h)
		glOrtho(-100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
	else
		glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("To moj pierwszy program w GLUT.");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();
	return 0;
}