#include "KeyBoardControl.h"
#include "UniverseCameraParameters.h"
#include <stdlib.h>
#include <stdio.h>
#include "Planets.h"


KeyBoardControl::KeyBoardControl()
{
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
	case '8': UniverseCameraParameters::camB += 2.0f;					break; // Forward
	case '5': UniverseCameraParameters::camB -= 2.0f;					break; // Back up
	case '4': UniverseCameraParameters::cameraViewAngle++;	printf("4 called");			break; // Move to the Right
	case '6': UniverseCameraParameters::cameraViewAngle--;	printf("6 called");			break; // Move to the Left

	case '9': UniverseCameraParameters::camA -= 2.0f;	UniverseCameraParameters::camB += 2.0f;	break; // Number 9 Rechts Boven
	case '1': UniverseCameraParameters::camA += 2.0f;	UniverseCameraParameters::camB -= 2.0f;	break; // Number 1 Links Beneden
	case '7': UniverseCameraParameters::camB += 2.0f;	UniverseCameraParameters::camA += 2.0f;	break; // Number 7 Links Boven
	case '3': UniverseCameraParameters::camB -= 2.0f;	UniverseCameraParameters::camA -= 2.0f;	break; // Number 3 Rechts Beneden

	case '2': UniverseCameraParameters::camC -= 2.0f;					break; // Elevate
	case '0': UniverseCameraParameters::camC += 2.0f;					break; // Descent

		////////Planetary Orbit Lanes Visibility:///////////////////////
	case 'o':	UniverseCameraParameters::visibility = !UniverseCameraParameters::visibility;	break;
		///////////////////////////////////////////////////////////////


		////////Solar System Animation/////////////////////////////////
	case 'a' : UniverseCameraParameters::animate = !UniverseCameraParameters::animate;			break;
		///////////////////////////////////////////////////////////////

		//////Lighting/////////////////////////////////////////////////
	case 'l': UniverseCameraParameters::light = !UniverseCameraParameters::light;				break;
		///////////////////////////////////////////////////////////////

	case 'r': UniverseCameraParameters::resetView = true;				break; // reset camera view to default position

	case 'm': Planets::showOrbitalLanes = !Planets::showOrbitalLanes;   break; // Draw Orbital Lanes

	case 't': UniverseCameraParameters::lightPosX++; break;
	case 'y': UniverseCameraParameters::lightPosY++; break;
	case 'u': UniverseCameraParameters::lightPosZ++; break;

	case 'g': UniverseCameraParameters::lightPosX--; break;
	case 'h': UniverseCameraParameters::lightPosY--; break;
	case 'j': UniverseCameraParameters::lightPosZ--; break;


	}
}