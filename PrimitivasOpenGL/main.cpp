#include <stdlib.h>
#include "GL/glut.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#pragma comment(lib, "glut32.lib")
#define WINDOW_TITLE "Tarea - Damaris"
using namespace std;
const float FOV = 70.f;
const float NCP = 0.001f;
const float FCP = 40.f;

int m_iWidth = 800;
int m_iHeight = 600;
float Rotation = 0.0f;

void idle(void)
{
	glutPostRedisplay();
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.6,0.6,0.6,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.7f, 0, -6.0);		// Traslacion
	glRotatef(Rotation, 0.0, 0.0, 1.0);	// Rotation
	glScalef(1.5, 1.5, 1.5);			// Escalado
	Rotation += 0.1f;

	glBegin(GL_POLYGON); //Cubo
		glVertex3f(-0.50, 0.50, -1);
		glVertex3f(0.50, 0.50, -1);
		glVertex3f(0.50, -0.50, -1);
		glVertex3f(-0.50, -0.50, -1);
	glEnd();

	glutSwapBuffers();
}

void reshape(int width, int height) 
{
	glViewport (0, 0, (GLsizei) width, (GLsizei) height);
 
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	float ratio = (height == 0)?1:(GLfloat) width/(GLfloat) height;
	gluPerspective(FOV, ratio, NCP, FCP);
 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

bool initialize()
{
	glEnable(GL_DEPTH_TEST);
	return true;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(m_iWidth, m_iHeight);
	glutCreateWindow(WINDOW_TITLE);
	if(!initialize()) return 1;
	glutDisplayFunc(draw);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}