#include "Neptune.h"


Neptune::Neptune()
{
	mUnknownRotationValue = 9;

	mPlanetCoordinates.xPosition = 140; //Default: 25 Mercury specific
	mPlanetCoordinates.yPosition = 0;  //Default: 0 Mercury specific
	mPlanetCoordinates.zPosition = 0;  //Default: 0 Mercury specific

	//glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);
	


	//glColor3f(0.6f, 0.5f, 0.7f); Don't call!
	mPlanetTextureFileName = "texture_neptune.bmp";

	//createTexturedPlanet parameters:
	mRadius = 4;			//Default: 8  Earth specific
	mSlices = 20;			//Default: 50 Earth specific
	mStacks = 10;			//Default: 50 Earth specific



	LoadPlanetImage((mPlanetTextureDefaultFolder += mPlanetTextureFileName).c_str());
}


Neptune::~Neptune()
{







}

void Neptune::Render()
{
	glPushMatrix();
	glRotatef(sunOrbitAngle, 0.0f, 1.0f, 0.0f); //responsible for creating an orbit lane for the planet
	sunOrbitAngle += 0.2f;

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

void Neptune::Update()
{

}
