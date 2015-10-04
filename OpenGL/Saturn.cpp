#include "Saturn.h"

Saturn::Saturn()
{
	mUnknownRotationValue = 7;

	mPlanetCoordinates.xPosition = 90; //Default: 25 Mercury specific
	mPlanetCoordinates.yPosition = 0;  //Default: 0 Mercury specific
	mPlanetCoordinates.zPosition = 0;  //Default: 0 Mercury specific

	//glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);

	//glColor3f(0.9f, 0.5f, 0.1f); // darker yellow - PROBLEMS WITH THIS LINE HERE! DON'T CALL!
	mPlanetTextureFileName = "texture_saturn.bmp";

	//createTexturedPlanet parameters:
	mRadius = 5;			//Default: 8  Earth specific
	mSlices = 20;			//Default: 50 Earth specific
	mStacks = 10;			//Default: 50 Earth specific

	LoadPlanetImage((mPlanetTextureDefaultFolder += mPlanetTextureFileName).c_str());
	SetSize(23);
	SetPosition(600, 0, 0);
}

Saturn::~Saturn()
{
}

void Saturn::Render()
{
	glPushMatrix();
	glRotatef(sunOrbitAngle, 0.0f, 1.0f, 0.0f); //responsible for creating an orbit lane for the planet
	sunOrbitAngle += 0.4f;

	glPushMatrix();

	glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);

	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Default angle of a planet. If you don't want the planet's texture to look upside down, keep this one as it is.

	glRotatef(planetOrbitAngle, 0.0f, 0.0f, 1.0f);
	planetOrbitAngle += 0.2f;
	CreateTexturedPlanet(mRadius, mSlices, mStacks);

	glPopMatrix();
	glPopMatrix();
	//return mRenderStatus;
}

void Saturn::Update()
{
}