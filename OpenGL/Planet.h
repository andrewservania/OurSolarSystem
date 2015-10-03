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
#include "IRenderableObject.h"
using namespace std;

class Planet : public IRenderableObject
{
protected:
	bool mShowOrbitalLanes;
	float mColorValue;


	bool mIsImageLoaded;

	string mPlanetTextureDefaultFolder;
	string mPlanetTextureFileName;

	bool mRenderStatus;
	float mSolarSystemRotation;

	GLuint mTextureIDPlanet;
	GLUquadric *mQuadPlanet;



	GLfloat mRadius;
	int mSlices;
	int mStacks;

//	GLfloat mCustomValue; //TODO: Figure out this necessary Value! Is used as parameter for DrawOrbit() method in Planet.cpp
	int mUnknownRotationValue;

	/* To return complete planet coordinates in one data-structure*/
	struct PlanetCoordinates{
		GLfloat xPosition;
		GLfloat yPosition;
		GLfloat zPosition;
	} mPlanetCoordinates;

public:
	Planet();
	~Planet();
	
	virtual void Render() override; //virtual in order to make it override-able. Meaning, you can have a Render() function with specific code for every planet object that you create.
	//OTHER the created planet will just use the code implemented in the render() function of Planet.cpp
	GLuint LoadPlanetTexture(Image* image);
	void LoadPlanetImage(const char* fileName);
	void CreateTexturedPlanet(GLfloat radius, int slices, int stacks);
	void DrawOrbit(GLfloat radius, int numPoints, bool visible, GLfloat customV);

	//*Standard Planet getters*/
	GLfloat GetX();
	GLfloat GetY();
	GLfloat GetZ();

	PlanetCoordinates GetPosition();
	GLfloat GetSize();

	/*Standard Planet setters*/
	void SetX(GLfloat value);
	void SetY(GLfloat value);
	void SetZ(GLfloat value);

	void SetPosition(GLfloat x, GLfloat y, GLfloat z);
	void SetPosition(PlanetCoordinates planetCoordinates);
	void SetSize(GLfloat radius);
};
