#include "KeyBoardControl.h"
#include <stdlib.h>
#include <stdio.h>
#include "Planets.h"

KeyBoardControl::KeyBoardControl()
{

}
KeyBoardControl::KeyBoardControl(Planets* planets, UniverseCameraParameters* camera)
{
	mPlanets = planets;
	mCamera = camera;
}

KeyBoardControl::~KeyBoardControl()
{
}

void KeyBoardControl::ListenToKeys(unsigned char key, int x, int y)
{
	printf("KeyBoardControlClass: Listening to keys");
	switch (key)
	{
	case 27:  exit(0);					break;  // ESCAPE key terminate Program

		///////////Nummeric Keypad Camera Movement Implementation: /////////////////
	case '8': mCamera->camB += 2.0f;															break; // Forward
	case '5': mCamera->camB -= 2.0f;															break; // Back up
	case '4': mCamera->cameraViewAngle++;							printf("4 called");			break; // Move to the Right
	case '6': mCamera->cameraViewAngle--;							printf("6 called");			break; // Move to the Left

	case '9': mCamera->camA -= 2.0f;	mCamera->camB += 2.0f;									break; // Number 9 Rechts Boven
	case '1': mCamera->camA += 2.0f;	mCamera->camB -= 2.0f;									break; // Number 1 Links Beneden
	case '7': mCamera->camB += 2.0f;	mCamera->camA += 2.0f;									break; // Number 7 Links Boven
	case '3': mCamera->camB -= 2.0f;	mCamera->camA -= 2.0f;									break; // Number 3 Rechts Beneden

	case '2': mCamera->camC -= 2.0f;															break; // Elevate
	case '0': mCamera->camC += 2.0f;															break; // Descent

		////////Planetary Orbit Lanes Visibility:///////////////////////
	case 'o':	mCamera->visibility = !mCamera->visibility;										break;
		///////////////////////////////////////////////////////////////


		////////Solar System Animation/////////////////////////////////
	case 'a' : mCamera->animate = !mCamera->animate;											break;
		///////////////////////////////////////////////////////////////

		//////Lighting/////////////////////////////////////////////////
	case 'l': mCamera->light = !mCamera->light;													break;
		///////////////////////////////////////////////////////////////

	case 'r': mCamera->resetView = true;														break; // reset camera view to default position

	case 'm': mPlanets->showOrbitalLanes = !mPlanets->showOrbitalLanes;							break; // Draw Orbital Lanes

	case 't': mCamera->lightPosX++;																break;
	case 'y': mCamera->lightPosY++;																break;
	case 'u': mCamera->lightPosZ++;																break;

	case 'g': mCamera->lightPosX--;																break;
	case 'h': mCamera->lightPosY--;																break;
	case 'j': mCamera->lightPosZ--;																break;


	}
}