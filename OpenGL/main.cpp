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
#include "Camera.h"
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
#include "OrbitLane.h"

using namespace std;



int FPS = 60; //Default value: 60

//Global variables:
float solarSystemRotation = 0;
float lineVertices[3] = { 0, 0, 0 };
float aaa = -20.0f, bbb = 0.0f, ccc = 0.0f;

GLuint _textureId; //The id of the texture
GLUquadric *quad;

//Planets*solarSystemPlanets;
KeyBoardControl*keyboardControl;
string fileLocationOfUniverses = "..\\OpenGL\\Resources\\Universe Background Pictures\\";

float mCameraRearDistance =  100;
float mCameraFrontDistance = 970;

Camera* mCamera;

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

//Planet lanes
unique_ptr<OrbitLane> mOrbitLane1;
unique_ptr<OrbitLane> mOrbitLane2;
unique_ptr<OrbitLane> mOrbitLane3;
unique_ptr<OrbitLane> mOrbitLane4;
unique_ptr<OrbitLane> mOrbitLane5;
unique_ptr<OrbitLane> mOrbitLane6;
unique_ptr<OrbitLane> mOrbitLane7;
unique_ptr<OrbitLane> mOrbitLane8;
unique_ptr<OrbitLane> mOrbitLane9;



string fontFilename = "...\\OpenGL\\Resources\\Fonts\\";
string fontName = "FreeSerif.ttf";


void drawText(string text,float x,float y,float z){
	//glMatrixMode(GL_PROJECTION);
	//glPushMatrix();
	//glLoadIdentity();
	//gluOrtho2D(0.0, mScreenWidth, 0.0, mScreenHeight);

	//glMatrixMode(GL_MODELVIEW);
	//glPushMatrix();
	//glLoadIdentity();

	glColor3f(0.0, 1.0, 0.0); // Green
	
	//glRasterPos3f(x, y, z);
	glRasterPos3f(-mCamera->camA, mCamera->camB, mCamera->camC);
	
	//glRasterPos2f(x, y);
	void * font = GLUT_BITMAP_9_BY_15;
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


void SetFPS(int framesPerSecond){

	FPS = framesPerSecond;
}

void renderAccordingToFPS(){
	Sleep(1000 / FPS);
}



//Display is called continuously. So this is your graphics loop.
void Render(void)
{
	
	
	//// The following line empties the buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt( mCamera->camA,  mCamera->camB,   -mCamera->camC,		//eye
			   mCamera->camA,  mCamera->camB,    mCamera->camC,		//center
			   0,			   1,				0);

	glRotatef(mCamera->cameraViewAngle, 0.0, 10.0, 0.0);
	
	glPushMatrix();
	glLineWidth(2.0);						// Width of ALL Lines in the 3D environment
	glPopMatrix();


	mUniverseBackground->Render();
	
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

	mOrbitLane1->Render(100);
	mOrbitLane2->Render(200);
	mOrbitLane3->Render(300);
	mOrbitLane4->Render(400);
	mOrbitLane5->Render(500);
	mOrbitLane6->Render(600);
	mOrbitLane7->Render(700);
	mOrbitLane8->Render(800);
	mOrbitLane9->Render(900);



	//mAxes->RenderXAxisGrid();
    //mAxes->RenderYAxisGrid();
	//mAxes->RenderZAxisGrid();

	//glLoadIdentity();

	glutSwapBuffers();
	renderAccordingToFPS();
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


void MouseButton(int button, int state, int x, int y)
{


}

//mouseWheel ZoomIn ZoomOut
void mouseWheel(int button, int dir, int x, int y)
{

	if (dir > 0)
	{
		// Rotate Up
		mCamera->camC -= 8.0f;					// Forward
		cout << mCamera->camC << "      \r";
	}
	else
	{
		// Rotate Down
		mCamera->camC += 8.0f;					// Back up
		cout << mCamera->camC << "      \r";
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

	//Vertical checking
	//if (mCamera->camB >= mCameraFrontDistance)
	//	mCamera->camB = mCameraFrontDistance;

	//if (mCamera->camB <= mCameraRearDistance)
	//	mCamera->camB = mCameraRearDistance;

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

		if (mCamera->camA == 20 
			&& mCamera->camB == -60 
			&& mCamera->camC == -5 
			&& aaa == -20)
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


void arrowPadInput(int key, int x, int y){
	switch (key){
	case GLUT_KEY_UP :
		//do something here
		mCamera->camB+=10;
		break;
	case GLUT_KEY_DOWN:
		//do something here
		mCamera->camB -= 10;
		break;
	case GLUT_KEY_LEFT:
		//do something here
		//solarSystemRotation += 1.0f;
		mCamera->cameraViewAngle += 1.0f;
		glRotatef(mCamera->cameraViewAngle, 0.0, 10.0, 0.0);
		break;
	case GLUT_KEY_RIGHT:
		//solarSystemRotation -= 1.0f;
		mCamera->cameraViewAngle -= 1.0f;
		glRotatef(mCamera->cameraViewAngle, 0.0, 10.0, 0.0);
		//do something here
		break;
	}
}

int main(int argc, char* argv[])
{
	cout << "Loading...\n";
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	
	mCamera = new Camera();

	//solarSystemPlanets = new Planets();
	keyboardControl = new KeyBoardControl(mCamera);

	//glEnable(GL_LIGHTING);
	keyboardControl->ToggleFullScreen(false);
	//Advanced experiment. Smart Pointers
	mUniverseBackground = make_unique<UniverseBackground>(1000);
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
	mJupiter->SetPosition(500, 0, 0);
	mSaturn->SetPosition(600, 0, 0);
	mUranus->SetPosition(700, 0, 0);
	mNeptune->SetPosition(800, 0, 0);
	mPluto->SetPosition(900, 0, 0);

	mMercury->SetSize(5);
	mVenus->SetSize(6);
	mEarth->SetSize(40);
	mMars->SetSize(10);
	mJupiter->SetSize(27);
	mSaturn->SetSize(23);
	mUranus->SetSize(19);
	mNeptune->SetSize(18);
	mPluto->SetSize(3);

	//mAxes = make_unique<Axes>();
	
	mOrbitLane1 = make_unique<OrbitLane>();
	mOrbitLane2 = make_unique<OrbitLane>();
	mOrbitLane3 = make_unique<OrbitLane>();
	mOrbitLane4 = make_unique<OrbitLane>();
	mOrbitLane5 = make_unique<OrbitLane>();
	mOrbitLane6 = make_unique<OrbitLane>();
	mOrbitLane7 = make_unique<OrbitLane>();
	mOrbitLane8 = make_unique<OrbitLane>();
	mOrbitLane9 = make_unique<OrbitLane>();




	SetFPS(60);
	// Initialize OpenGL graphics state
	InitGraphics();

	// Register callbacks:
	glutDisplayFunc(Render);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(KeyboardFunc);
	glutMouseFunc(MouseButton);
	glutMotionFunc(MouseMotion);
	glutMouseWheelFunc(mouseWheel);
	glutIdleFunc(IdleFunc);
	glutSpecialFunc(arrowPadInput);

	cout << "Done.\n";
	// Turn the flow of control over to GLUT
	glutMainLoop();

	return 0;
}

