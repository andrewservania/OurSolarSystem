#include "Sun.h"


Sun::Sun()
{
	//glColor3f(1.0f, 1.0f, 0.0f);


	mUnknownRotationValue = 3;

	mPlanetCoordinates.xPosition = 0; //Default: 40 Venus specific
	mPlanetCoordinates.yPosition = 0;  //Default: 0 Mercury specific
	mPlanetCoordinates.zPosition = 0;  //Default: 0 Mercury specific

	//glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);

	//glColor3f(0.7f, 0.6f, 0.0f); //brown
	mPlanetTextureFileName = "texture_sun.bmp";

	//createTexturedPlanet parameters:
	mRadius = 40;			//Default: 8  Earth specific
	mSlices = 40;			//Default: 50 Earth specific
	mStacks = 40;			//Default: 50 Earth specific



	LoadPlanetImage((mPlanetTextureDefaultFolder += mPlanetTextureFileName).c_str());

}


Sun::~Sun()
{
}
	
void Sun::Render()
{

	glPushMatrix();

	glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);

	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Default angle of a planet. If you don't want the planet's texture to look upside down, keep this one as it is.


	glRotatef(planetOrbitAngle, 0.0f, 0.0f, 1.0f);
	planetOrbitAngle += 0.2f;
	CreateTexturedPlanet(mRadius, mSlices, mStacks);


	glPopMatrix();
//	return mRenderStatus;
}

void Sun::Update()
{

}