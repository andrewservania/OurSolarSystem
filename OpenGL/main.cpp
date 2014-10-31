//OpenGL 3D Computer Graphics
//Name: Andrew's Funky Finite 3D Solar System
//Author: Andrew Servania

#include <iostream>
#include "glut.h"
#include "freeglut.h"
#include "GL.h"
#include <windows.h>
#include "Planets.h"
#include "imageloader.h"
#include "UniverseCameraParameters.h"
#include "KeyBoardControl.h"

using namespace std;


float solarSystemRotation = 0;
float lineVertices[3] = { 0, 0, 0 };
float aaa = -20.0f, bbb = 0.0f, ccc = 0.0f;
GLuint _textureId; //The id of the texture
GLUquadric *quad;
Planets*solarSystemPlanets;
KeyBoardControl*keyboardControl;

GLuint loadTexture(Image* image) {

	GLuint textureId;

	glGenTextures(1, &textureId); //Make room for our texture

	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit

	//Map the image to the texture

	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D

		0,                            //0 for now

		GL_RGB,                       //Format OpenGL uses for image

		image->width, image->height,  //Width and height

		0,                            //The border of the image

		GL_RGB, //GL_RGB, because pixels are stored in RGB format

		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored

		//as unsigned numbers

		image->pixels);               //The actual pixel data

	return textureId; //Returns the id of the texture

}

void ToggleWireVsUniverseCreation(bool createUniverse)
{

	if (createUniverse == true)
	{

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, _textureId);

		gluQuadricTexture(quad, 1);

		gluSphere(quad, 300, 50, 50);


	}
	else
	{
		glColor3f(0.0f, 0.0f, 1.0f);
		glutWireSphere(280, 200, 256);
	}


}

void Display(void)
{
	//// The following line empties the buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(
		0 + UniverseCameraParameters::camA, -1 + UniverseCameraParameters::camB, -1 + UniverseCameraParameters::camC,		//eye
		0 + UniverseCameraParameters::camA, 2 + UniverseCameraParameters::camB, 0 + UniverseCameraParameters::camC,		//center
		0, 1, 0);						// up vector THIS ONE STAYS LIKE ThIS! UNLESS YOU WANT TO WORK WITH HEIGHTS!

	glRotatef(UniverseCameraParameters::cameraViewAngle + 200, 0.0, 0.0, 1.0);
	ToggleWireVsUniverseCreation(true);
	glPushMatrix();
	glLineWidth(2.0);						// Width of ALL Lines in the 3D enviroment
	glPopMatrix();

	//// Sphere experimentation
	////glutWireSphere() Function Technical Details:
	////First variable:  radius: The radius of the sphere. 
	////Second Variable: slices: The number of subdivisions around the Z axis (similar to lines of longitude). 
	////Third Variable:  stacks: The number of subdivisions along the Z axis (similar to lines of latitude). 
	////Description: Renders a sphere centered at the modeling coordinates origin of the specified radius. 
	////			   The sphere is subdivided around the Z axis into slices and along the Z axis into stacks.

	////Rotate on the x axis
	glRotatef(aaa, 1.0, 0.0, 0.0);

	////Rotate on the y axis VERY IMPORTANT (universe is not upside down due to this:)
	glRotatef(180, 0.0, 1.0, 0.0);

	////emit light from the next sphere object
	////GLfloat mat_emission[] = {0.3, 0.2, 0.2, 1.0};
	////glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

	////Sun:
	//////The Sun//////////////////////////////////////////////////////////
	glColor3f(1.0f, 1.0f, 0.0f); //yellow
	glutSolidSphere(8, 20, 10);
	///////////////////////////////////////////////////////////////////////



	//NOTE!! StackOverflow suggestion:
	//I've just noticed the first line of your question - 
	//you don't want to make those functions static, 
	//you want to make them const. Making them static means 
	//that they are no longer associated with an object 
	//(so they can't access any non-static members), 
	//and making the data static means it will be shared with 
	//all objects of this type. This may well not be what you want. 
	//Making them const simply means that they can't modify any members, but can still access them




	solarSystemPlanets->CreateJupiter(solarSystemRotation);
	solarSystemPlanets->CreateMars(solarSystemRotation);
	solarSystemPlanets->CreateMercury(solarSystemRotation);
	solarSystemPlanets->CreateNeptunus(solarSystemRotation);
	solarSystemPlanets->CreatePlanetEarth(solarSystemRotation);
	solarSystemPlanets->CreatePluto(solarSystemRotation);
	solarSystemPlanets->CreateSaturn(solarSystemRotation);
	solarSystemPlanets->CreateUranus(solarSystemRotation);
	solarSystemPlanets->CreateVenus(solarSystemRotation);





	glutSwapBuffers();

}

void Reshape(GLint width, GLint height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, width / (float)height, 1, 2000);
	glMatrixMode(GL_MODELVIEW);
}

void InitGraphics(void)
{

	glEnable(GL_DEPTH_TEST);

	//	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);

	glEnable(GL_NORMALIZE);

	glEnable(GL_COLOR_MATERIAL);

	printf("Init Graphics method called");

	quad = gluNewQuadric();

	Image* image = loadBMP("universe4.bmp");

	_textureId = loadTexture(image);

	delete image;

	solarSystemPlanets = new Planets();

}

// Andy: If this function is NOT called. All elements will get a static bright color
void letThereBeLight()
{
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);

	GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 0.0 };
	GLfloat mat_shininess[] = { 40.0 };

	GLfloat light_position[] = {
		0.0f + UniverseCameraParameters::lightPosX,
		1.0f + UniverseCameraParameters::lightPosY,
		1.0f + UniverseCameraParameters::lightPosZ, -0.3f };


	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);

	if (UniverseCameraParameters::light == true)
	{
		glEnable(GL_LIGHT0);
	}
	else
	{
		glDisable(GL_LIGHT0);
	}
	glEnable(GL_DEPTH_TEST);
}

void MouseButton(int button, int state, int x, int y)
{


}

//mouseWheel ZoomIn ZoomOut
void mouseWheel(int button, int dir, int x, int y)
{

	if (dir > 0)
	{
		// Rotate Up
		UniverseCameraParameters::camB += 2.0f;					// Forward

	}
	else
	{
		// Rotate Down
		UniverseCameraParameters::camB -= 2.0f;					// Back up
	}
}

void MouseMotion(int x, int y)
{

}

void IdleFunc(void)
{
	// Hier update ik alles qua graphics,
	// dan hoef ik niet elke keer op nieuw gluPostRedisplay te gebruiken.

	//3D Camera Environment Limits///////////
	if (UniverseCameraParameters::camA >= 160)
		UniverseCameraParameters::camA = 160;

	if (UniverseCameraParameters::camA <= -160)
		UniverseCameraParameters::camA = -160;

	if (UniverseCameraParameters::camB >= 160)
		UniverseCameraParameters::camB = 160;

	if (UniverseCameraParameters::camB <= -160)
		UniverseCameraParameters::camB = -160;

	if (UniverseCameraParameters::camC >= 160)
		UniverseCameraParameters::camC = 160;

	if (UniverseCameraParameters::camC <= -160)
		UniverseCameraParameters::camC = -160;
	///////////////////////////////////////////
	if (UniverseCameraParameters::visibility == true)
	{
		UniverseCameraParameters::colorValue = -1.0f;
		glutPostRedisplay();
	}
	if (UniverseCameraParameters::visibility == false)
	{
		UniverseCameraParameters::colorValue = -3.5f;
		glutPostRedisplay();
	}

	if (UniverseCameraParameters::animate == true)
	{
		solarSystemRotation += 1.0f;
		UniverseCameraParameters::cameraViewAngle -= 0.05f;
	}
	//Gradual Camera Reset///////////
	while (UniverseCameraParameters::resetView == true)
	{
		if (UniverseCameraParameters::camA > 20)
		{
			UniverseCameraParameters::camA = UniverseCameraParameters::camA -= 1;

			if (UniverseCameraParameters::camA == 20)
			{
				UniverseCameraParameters::camA = 20;
			}

		}
		if (UniverseCameraParameters::camA < 20)
		{
			UniverseCameraParameters::camA = UniverseCameraParameters::camA += 1;

			if (UniverseCameraParameters::camA == 20)
			{
				UniverseCameraParameters::camA = 20;
			}
		}

		////////////////////////////////////////////
		if (UniverseCameraParameters::camB <-60)
		{
			UniverseCameraParameters::camB = UniverseCameraParameters::camB += 1;

			if (UniverseCameraParameters::camB == -60)
			{
				UniverseCameraParameters::camB = -60;
			}

		}
		if (UniverseCameraParameters::camB >-60)
		{
			UniverseCameraParameters::camB = UniverseCameraParameters::camB -= 1;
			if (UniverseCameraParameters::camB == -60)
			{
				UniverseCameraParameters::camB = -60;
			}
		}
		////////////////////////////////////////////
		if (UniverseCameraParameters::camC <-5)
		{
			UniverseCameraParameters::camC = UniverseCameraParameters::camC += 1;
			if (UniverseCameraParameters::camC == -5)
			{
				UniverseCameraParameters::camC = -5;
			}

		}
		if (UniverseCameraParameters::camC > -5)
		{
			UniverseCameraParameters::camC = UniverseCameraParameters::camC -= 1;
			if (UniverseCameraParameters::camC == -5)
			{
				UniverseCameraParameters::camC = -5;
			}
		}
		////////////////////////////////////////////
		if (aaa <-20)
		{
			aaa = aaa += 1;
			if (aaa == -20)
			{
				aaa = -20;
			}

		}
		if (aaa >-20)
		{
			aaa = aaa -= 1;
			if (aaa == -20)
			{
				aaa = -20;
			}
		}
		//////////////////////////////////////////	

		if (UniverseCameraParameters::camA == 20 && UniverseCameraParameters::camB == -60 && UniverseCameraParameters::camC == -5 && aaa == -20)
		{
			UniverseCameraParameters::resetView = false;
		}
	}

	letThereBeLight();
	glutPostRedisplay();

}

void KeyboardFunc(unsigned char key, int x, int y)
{
	keyboardControl->ListenToKeys(key, x, y);
}

void ToggleFullScreen(bool isFullscreen)
{
	if (isFullscreen == true)
	{
		glutGameModeString("1366x768:32@60"); //the settings for fullscreen mode
		glutEnterGameMode(); //set glut to fullscreen using the settings in the line above
	}

	else
	{
		// These three functions HAVE to follow this order!
		// Otherwise you will BREAK the window!
		glutInitWindowSize(1000, 600);
		glutCreateWindow("Andrew's Funky 3D Finite Solar System");
		glutPositionWindow(150, 80);
	}

}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	ToggleFullScreen(true);
	keyboardControl = new KeyBoardControl(solarSystemPlanets);
	// Initialize OpenGL graphics state
	InitGraphics();
	// Register callbacks:
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(KeyboardFunc);
	glutMouseFunc(MouseButton);
	glutMotionFunc(MouseMotion);
	glutMouseWheelFunc(mouseWheel);
	glutIdleFunc(IdleFunc);
	// Turn the flow of control over to GLUT
	glutMainLoop();
	//oneBloodyMethod();
	return 0;
}

