#include "Axes.h"


Axes::Axes()
{
	mIsXBeingRendered = false, mIsXBeingRendered = false, mIsXBeingRendered = false;
	mIsXGridBeingRendered = false, mIsYGridBeingRendered = false, mIsZGridBeingRendered = false;
}


Axes::~Axes()
{
}

bool Axes::RenderXAxis()
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1000.0f, 0.0f, 0.0f);
	glEnd();
	
	mIsXBeingRendered = false;
	return mIsXBeingRendered;
}

bool Axes::RenderYAxis()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1000.0f, 0.0f);
	glEnd();
	
	mIsYBeingRendered = false;
	return mIsYBeingRendered;
}

bool Axes::RenderZAxis()
{
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1000.0f);
	glEnd();

	mIsZBeingRendered = false;
	return mIsZBeingRendered;
}

bool Axes::RenderXAxisGrid()
{

	glColor3f(1.0f, 0.0f, 0.0f);
	
	glBegin(GL_LINES);
	for (int i = 0; i <= 1000; i++){

		glVertex3f( 0.0f, 0.0f, 0.0f + i * 3);
		glVertex3f( 1000.0f, 0.0f, 0.0f + i * 3);

		glVertex3f(0.0f + i * 3, 0.0f, 0.0f);
		glVertex3f(0.0f + i * 3, 0.0f, 1000.0f);

	}

	glEnd();

	return mIsXGridBeingRendered;
}

bool Axes::RenderYAxisGrid()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);

	for (int i = 0; i <= 1000; i++){

		glVertex3f(0.0f + i * 3, 0.0f, 0.0f);
		glVertex3f(0.0f + i * 3, 1000.0f, 0.0f);

		glVertex3f( 0.0f, 0.0f + i * 3,0.0f);
		glVertex3f(1000.0f, 0.0f + i * 3, 0.0f);
	}

	glEnd();

	return mIsYGridBeingRendered;
}

bool Axes::RenderZAxisGrid()
{
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	for (int i = 0; i <= 1000; i++){

		glVertex3f(0.0f,0.0f + i * 3, 0.0f);
		glVertex3f(0.0f,0.0f + i * 3, 1000.0f );

		glVertex3f(0.0f, 0.0f, 0.0f + i * 3);
		glVertex3f(0.0f, 1000.0f, 0.0f + i * 3);
	}

	glEnd();
	return mIsZGridBeingRendered;
}
