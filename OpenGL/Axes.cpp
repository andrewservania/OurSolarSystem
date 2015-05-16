#include "Axes.h"


Axes::Axes()
{
	mIsXBeingRendered = false, mIsXBeingRendered = false, mIsXBeingRendered = false;
	mIsXGridBeingRendered = false, mIsYGridBeingRendered = false, mIsZGridBeingRendered = false;
	mLengthOfAxes = 100;
	squareSizeInGrid = 10;
	depth = squareSizeInGrid*mLengthOfAxes;
}

Axes::~Axes()
{
}

bool Axes::RenderXAxis()
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(mLengthOfAxes, 0.0f, 0.0f);
	glEnd();

	mIsXBeingRendered = false;
	return mIsXBeingRendered;
}

bool Axes::RenderYAxis()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, mLengthOfAxes, 0.0f);
	glEnd();

	mIsYBeingRendered = false;
	return mIsYBeingRendered;
}

bool Axes::RenderZAxis()
{
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, mLengthOfAxes);
	glEnd();
	
	mIsZBeingRendered = false;
	return mIsZBeingRendered;
}

bool Axes::RenderXAxisGrid()
{
	

	glColor3f(1.0f, 0.0f, 0.0f); /*Red*/
	glBegin(GL_LINES);
	for (int i = 0; i <= mLengthOfAxes; i++){

		glVertex3f(0.0f, 0.0f, 0.0f + i * squareSizeInGrid);
		glVertex3f(depth, 0.0f, i * squareSizeInGrid + 0.0f);       

	    glVertex3f(0.0f + i * squareSizeInGrid, 0.0f, 0.0f);
		glVertex3f(0.0f + i * squareSizeInGrid, 0.0f, depth + 0.0f);

	}
	glClearColor(0, 0, 0, 1);
	glEnd();
	for (int i = 0; i < depth; i++){

		if ((i % 100) == 0){
			drawText(to_string(i), i + 0.0f, 0 + 0.0f, 0 + 0.0f);
		}

	}
	return mIsXGridBeingRendered;
}

bool Axes::RenderYAxisGrid()
{
	glColor3f(0.0f, 1.0f, 0.0f);/*green*/
	glBegin(GL_LINES);

	for (int i = 0; i <= mLengthOfAxes; i++){

		glVertex3f(0.0f + i * squareSizeInGrid, 0.0f, 0.0f);
		glVertex3f(0.0f + i * squareSizeInGrid, depth, 0.0f);

		glVertex3f( 0.0f, 0.0f + i * squareSizeInGrid,0.0f);
		glVertex3f(depth, 0.0f + i * squareSizeInGrid, 0.0f);
	}
	
	glEnd();

	for (int i = 0; i < depth; i++){

		if ((i % 100) == 0){
			drawText(to_string(i), 0 + 0.0f, i + 0.0f, 0 + 0.0f);
		}

	}
	return mIsYGridBeingRendered;
}

bool Axes::RenderZAxisGrid()
{

	glColor3f(0.0f, 0.0f, 1.0f);/*blue*/
	//glPushAttrib(GL_CURRENT_BIT);
	glBegin(GL_LINES);
	for (int i = 0; i <= mLengthOfAxes; i++){

		glVertex3f(0.0f,0.0f + i * squareSizeInGrid, 0.0f);
		glVertex3f(0.0f, 0.0f + i * squareSizeInGrid, depth + 0.0f);

		glVertex3f(0.0f, 0.0f, 0.0f + i * squareSizeInGrid);
		glVertex3f(0.0f, depth, 0.0f + i * squareSizeInGrid);
	}

	glEnd();

	for (int i = 0; i < depth; i++){

		if ((i % 100)==0 ){
			drawText(to_string(i), 0.0f, 0.0f, i + 0.0f);
		}
		
	}
	

	return mIsZGridBeingRendered;
}

void Axes::drawText(string text, float x, float y, float z)
{
	//glMatrixMode(GL_PROJECTION);
	//glPushMatrix();
	//glLoadIdentity();
	//gluOrtho2D(0.0, mScreenWidth, 0.0, mScreenHeight);

	//glMatrixMode(GL_MODELVIEW);
	//glPushMatrix();
	//glLoadIdentity();

	glColor3f(0.0, 1.0, 0.0); // Green

	//glRasterPos3f(x, y, z);
	glRasterPos3f(x, y, z);

	//glRasterPos2f(x, y);
	void * font = GLUT_BITMAP_TIMES_ROMAN_24;
	for (string::iterator i = text.begin(); i != text.end(); ++i)
	{
		char c = *i;
		glutBitmapCharacter(font, c);
	}
	//glMatrixMode(GL_MODELVIEW);
	//glPopMatrix();

	//glMatrixMode(GL_PROJECTION);
	//glPopMatrix();

}
