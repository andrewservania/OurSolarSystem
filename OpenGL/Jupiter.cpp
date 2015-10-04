#include "Jupiter.h"

Jupiter::Jupiter()
{
	//glPushMatrix();
	mUnknownRotationValue = 6;
	mPlanetCoordinates.xPosition = 75; //Default: 25 Mercury specific
	mPlanetCoordinates.yPosition = 0;  //Default: 0 Mercury specific
	mPlanetCoordinates.zPosition = 0;  //Default: 0 Mercury specific

	//glTranslatef(mPlanetCoordinates.xPosition, mPlanetCoordinates.yPosition, mPlanetCoordinates.zPosition);

	mPlanetTextureFileName = "texture_jupiter.bmp";
	//glColor3f(0.4f, 0.3f, 0.2f); //lime green <-THIS glCOLOR caused Color chaos for the WHOLE solar system!
	//DON'T CALL AGAIN!
	//createTexturedPlanet parameters:
	mRadius = 6;			//Default: 8  Earth specific
	mSlices = 20;			//Default: 50 Earth specific
	mStacks = 10;			//Default: 50 Earth specific

	LoadPlanetImage((mPlanetTextureDefaultFolder += mPlanetTextureFileName).c_str());

	SetSize(27);
	SetPosition(500, 0, 0);
}

Jupiter::~Jupiter()
{
}

void Jupiter::Render()
{
	glPushMatrix();
	glRotatef(sunOrbitAngle, 0.0f, 1.0f, 0.0f); //responsible for creating an orbit lane for the planet
	sunOrbitAngle += 0.5f;

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

void Jupiter::Update()
{
}