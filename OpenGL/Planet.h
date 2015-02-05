//Major code improvement
// Andrew Servania
//01-Feb-2015
#pragma once
#include <string>
#include <windows.h>
#include "glut.h"
#include "freeglut.h"
#include "gl/GL.h"
#include "imageloader.h"

using namespace std;

class Planet
{
protected:
	bool mShowOrbitalLanes;
	float mColorValue;
	bool mVisibility;
	bool mIsImageLoaded;
	string mPlanetTextureDefaultFolder;
	string mPlanetTextureFileName;
	bool mRenderStatus;
	float mSolarSystemRotation;

	GLuint mTextureIDPlanet;
	GLUquadric *mQuadPlanet;

	GLfloat mOrbitRadius;
	int mNumberOfPoints;

	int mRadius;
	int mSlices;
	int mStacks;



	GLfloat mCustomValue; //TODO: Figure out this necessary Value! Is used as parameter for DrawOrbit() method in Planet.cpp

	/* To return complete planet coordinates in one data-structure*/
	struct PlanetCoordinates{
		GLfloat xPosition;
		GLfloat yPosition;
		GLfloat zPosition;
	} mPlanetCoordinates;

	int mUnknownRotationValue;


public:
	Planet();
	~Planet();
	void SetVisibility(bool visibility);
	bool Render();
	GLuint LoadPlanetTexture(Image* image);
	void LoadPlanetImage(const char* fileName);
	void CreateTexturedPlanet( int radius, int slices, int stacks);
	void DrawOrbit(GLfloat radius, int numPoints,bool visible, GLfloat customV);

	//*Standard Planet getters*/
	GLfloat GetX();
	GLfloat GetY();
	GLfloat GetZ();
	PlanetCoordinates GetPosition();
	int GetSize();

	/*Standard Planet setters*/
	void SetX(GLfloat value);
	void SetY(GLfloat value);
	void SetZ(GLfloat value);
	void SetPosition(GLfloat x, GLfloat y, GLfloat z );
	void SetPosition(PlanetCoordinates planetCoordinates);
	void SetSize(int radius);

};

