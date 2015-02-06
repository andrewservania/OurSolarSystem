//OpenGL 3D Computer Graphics
//Name: Andrew's Funky Finite 3D Solar System
//Author: Andrew Servania

#include <iostream>
#include <memory>
#include <windows.h>

#include "glut.h"
#include "freeglut.h"
#include "GL.h"

#include "Planets.h"
#include "imageloader.h"
#include "UniverseCameraParameters.h"
#include "KeyBoardControl.h"
#include "Mercury.h"
#include "Venus.h"
#include "Earth.h"
#include "Mars.h"
#include "Jupiter.h"
#include "Saturn.h"
#include "Uranus.h"
#include "Neptune.h"
#include "Pluto.h"
#include "Sun.h"

#include "UniverseBackground.h"
#include "Axes.h"

using namespace std;

//Global variables:
float solarSystemRotation = 0;
float lineVertices[3] = { 0, 0, 0 };
float aaa = -20.0f, bbb = 0.0f, ccc = 0.0f;

GLuint _textureId; //The id of the texture
GLUquadric *quad;

Planets*solarSystemPlanets;
KeyBoardControl*keyboardControl;
string fileLocationOfUniverses = "..\\OpenGL\\Resources\\Universe Background Pictures\\";


float mCameraRearDistance = -2000;
float mCameraFrontDistance = 2000;



UniverseCameraParameters* mCamera;

unique_ptr<Sun> mSun;
unique_ptr<Mercury> mMercury;
unique_ptr<Venus> mVenus;
unique_ptr<Earth> mEarth;
unique_ptr<Mars> mMars;
unique_ptr<Jupiter> mJupiter;
unique_ptr<Saturn> mSaturn;
unique_ptr<Uranus> mUranus;
unique_ptr<Neptune> mNeptune;
unique_ptr<Pluto> mPluto;

unique_ptr<UniverseBackground> mUniverseBackground;
unique_ptr<Axes> mAxes;

//GLuint loadTexture(Image* image) {
//
//	GLuint textureId;
//	glGenTextures(1, &textureId); //Make room for our texture
//	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
//	//Map the image to the texture
//	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
//		0,                            //0 for now
//		GL_RGB,                       //Format OpenGL uses for image
//		image->width, image->height,  //Width and height
//		0,                            //The border of the image
//		GL_RGB, //GL_RGB, because pixels are stored in RGB format
//		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
//		//as unsigned numbers
//		image->pixels);               //The actual pixel data
//
//	return textureId; //Returns the id of the texture
//}

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



//Display is called continuously. So this is your graphics loop.
void Display(void)
{
	//// The following line empties the buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(
		0 + mCamera->camA, -1 + mCamera->camB, -1 + mCamera->camC,		//eye
		0 + mCamera->camA, 2 + mCamera->camB, 0 + mCamera->camC,		//center
		0, 1, 0);						// up vector THIS ONE STAYS LIKE ThIS! UNLESS YOU WANT TO WORK WITH HEIGHTS!

	glRotatef(mCamera->cameraViewAngle + 200, 0.0, 0.0, 1.0);
	
	//Show Universe background picture
	//ToggleWireVsUniverseCreation(false);
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



	
	

	//NOTE!! StackOverflow suggestion:
	//I've just noticed the first line of your question - 
	//you don't want to make those functions static, 
	//you want to make them const. Making them static means 
	//that they are no longer associated with an object 
	//(so they can't access any non-static members), 
	//and making the data static means it will be shared with 
	//all objects of this type. This may well not be what you want. 
	//Making them const simply means that they can't modify any members, but can still access them
	mUniverseBackground->RenderUniverseBackground();


	//////The Sun//////////////////////////////////////////////////////////
	//glColor3f(1.0f, 1.0f, 0.0f); //yellow
	//glutSolidSphere(8, 20, 10);
	///////////////////////////////////////////////////////////////////////

	mSun->Render();

	mMercury->Render();

	mVenus->Render();

	mEarth->Render();

	mMars->Render();

	mJupiter->Render();

	mSaturn->Render();

	mUranus->Render();

	mNeptune->Render();

	mPluto->Render();

	mAxes->RenderXAxis();
	mAxes->RenderYAxis();
	mAxes->RenderZAxis();

	mAxes->RenderXAxisGrid();
	mAxes->RenderYAxisGrid();
	mAxes->RenderZAxisGrid();
	//glLoadIdentity();

	//solarSystemPlanets->CreateMercury(solarSystemRotation);
	//solarSystemPlanets->CreateVenus(solarSystemRotation);
	//solarSystemPlanets->CreatePlanetEarth(solarSystemRotation);
	//solarSystemPlanets->CreateMars(solarSystemRotation);
	//solarSystemPlanets->CreateJupiter(solarSystemRotation);
	//solarSystemPlanets->CreateSaturn(solarSystemRotation);
	//solarSystemPlanets->CreateUranus(solarSystemRotation);
	//solarSystemPlanets->CreateNeptunus(solarSystemRotation);
	//solarSystemPlanets->CreatePluto(solarSystemRotation);




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

	//glEnable(GL_DEPTH_TEST);

	////	glEnable(GL_LIGHTING);

	//glEnable(GL_LIGHT0);

	//glEnable(GL_NORMALIZE);

	//glEnable(GL_COLOR_MATERIAL);

	//printf("Init Graphics method called");

	//quad = gluNewQuadric();

	//Image* image = loadBMP((fileLocationOfUniverses + "universe4.bmp").c_str());

	//_textureId = loadTexture(image);

	//delete image;

	//solarSystemPlanets = new Planets();

}

// Andy: If this function is NOT called. All elements will get a static bright color
void letThereBeLight()
{
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);

	GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 0.0 };
	GLfloat mat_shininess[] = { 40.0 };

	GLfloat light_position[] = {
		0.0f + mCamera->lightPosX,
		1.0f + mCamera->lightPosY,
		1.0f + mCamera->lightPosZ, -0.3f };


	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);

	if (mCamera->light == true)
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
		mCamera->camB += 2.0f;					// Forward

	}
	else
	{
		// Rotate Down
		mCamera->camB -= 2.0f;					// Back up
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
	if (mCamera->camA >= mCameraFrontDistance)
		mCamera->camA = mCameraFrontDistance;

	if (mCamera->camA <= mCameraRearDistance)
		mCamera->camA = mCameraRearDistance;

	if (mCamera->camB >= mCameraFrontDistance)
		mCamera->camB = mCameraFrontDistance;

	if (mCamera->camB <= mCameraRearDistance)
		mCamera->camB = mCameraRearDistance;

	if (mCamera->camC >= mCameraFrontDistance)
		mCamera->camC = mCameraFrontDistance;

	if (mCamera->camC <= mCameraRearDistance)
		mCamera->camC = mCameraRearDistance;
	///////////////////////////////////////////
	if (mCamera->visibility == true)
	{
		mCamera->colorValue = -1.0f;
		glutPostRedisplay();
	}
	if (mCamera->visibility == false)
	{
		mCamera->colorValue = -3.5f;
		glutPostRedisplay();
	}

	if (mCamera->animate == true)
	{
		solarSystemRotation += 1.0f;
		mCamera->cameraViewAngle -= 0.05f;
	}
	//Gradual Camera Reset///////////
	while (mCamera->resetView == true)
	{
		if (mCamera->camA > 20)
		{
			mCamera->camA = mCamera->camA -= 1;

			if (mCamera->camA == 20)
			{
				mCamera->camA = 20;
			}

		}
		if (mCamera->camA < 20)
		{
			mCamera->camA = mCamera->camA += 1;

			if (mCamera->camA == 20)
			{
				mCamera->camA = 20;
			}
		}

		////////////////////////////////////////////
		if (mCamera->camB <-60)
		{
			mCamera->camB = mCamera->camB += 1;

			if (mCamera->camB == -60)
			{
				mCamera->camB = -60;
			}

		}
		if (mCamera->camB >-60)
		{
			mCamera->camB = mCamera->camB -= 1;
			if (mCamera->camB == -60)
			{
				mCamera->camB = -60;
			}
		}
		////////////////////////////////////////////
		if (mCamera->camC <-5)
		{
			mCamera->camC = mCamera->camC += 1;
			if (mCamera->camC == -5)
			{
				mCamera->camC = -5;
			}

		}
		if (mCamera->camC > -5)
		{
			mCamera->camC = mCamera->camC -= 1;
			if (mCamera->camC == -5)
			{
				mCamera->camC = -5;
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

		if (mCamera->camA == 20 && mCamera->camB == -60 && mCamera->camC == -5 && aaa == -20)
		{
			mCamera->resetView = false;
		}
	}

	//TODO: Adapt! This method does alot related to lighting!:
	//letThereBeLight();
	//glutPostRedisplay();

}

void KeyboardFunc(unsigned char key, int x, int y)
{
	keyboardControl->ListenToKeys(key, x, y);
}

void ToggleFullScreen(bool isFullscreen)
{
	if (isFullscreen == true)
	{
		//glutGameModeString("1920x1080:32@60"); //the settings for fullscreen mode
		glutGameModeString("1366x768:32@60"); //the settings for fullscreen mode
		glutEnterGameMode(); //set glut to fullscreen using the settings in the line above
	}

	else
	{
		// These three functions HAVE to follow this order!
		// Otherwise you will BREAK the window!
		glutInitWindowSize(1200, 700);
		glutCreateWindow("Andrew's Funky 3D Finite Solar System");
		glutPositionWindow(60, 10);
	}

}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	//solarSystemPlanets = new Planets();
	ToggleFullScreen(false);


	//Advanced experiment. Smart Pointers
	mSun = make_unique<Sun>();
	mMercury = make_unique<Mercury>();
	mVenus = make_unique<Venus>();
	mEarth  = make_unique<Earth>();
	mMars = make_unique<Mars>();
	mJupiter = make_unique<Jupiter>();
	mSaturn = make_unique<Saturn>();
	mUranus = make_unique<Uranus>();
	mNeptune = make_unique<Neptune>();
	mPluto = make_unique<Pluto>();

	
	mMercury->SetPosition(100, 0, 0);
	mVenus->SetPosition(200, 0, 0);
	mEarth->SetPosition(300, 0, 0);
	mMars->SetPosition(400, 0, 0);
	mJupiter->SetPosition(600, 0, 0);
	mSaturn->SetPosition(800, 0, 0);
	mUranus->SetPosition(100, 0, 0);
	mNeptune->SetPosition(1200, 0, 0);
	mPluto->SetPosition(1400, 0, 0);

	mMercury->SetSize(5);
	mVenus->SetSize(6);
	mEarth->SetSize(20);
	mMars->SetSize(10);
	mJupiter->SetSize(27);
	mSaturn->SetSize(23);
	mUranus->SetSize(19);
	mNeptune->SetSize(18);
	mPluto->SetSize(3);

	mUniverseBackground = make_unique<UniverseBackground>();
	mAxes = make_unique<Axes>();
	//mMercury = new Mercury();
	//mVenus = new Venus();
	//mEarth = new Earth();
	//mMars = new Mars();
	//mJupiter = new Jupiter();
	//mSaturn = new Saturn();
	//mUranus = new Uranus();
	//mNeptune = new Neptune();
	//mPluto = new Pluto();


	mCamera = new UniverseCameraParameters();

	solarSystemPlanets = new Planets();
	keyboardControl = new KeyBoardControl(solarSystemPlanets, mCamera);

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

	return 0;
}

