#include "UniverseCameraParameters.h"




UniverseCameraParameters::UniverseCameraParameters()
{
	  camA = 20;
	  camB = -120;
	  camC = -60;

	  cameraViewAngle = 10.0f;
	  universeLoaded = false;

	  animate = true;
	  visibility = true;
	  colorValue = 0.0f;
	  light = true;
	  resetView = false;

	  lightPosX = 1;
	  lightPosY = 1;
	  lightPosZ = 1;

}


UniverseCameraParameters::~UniverseCameraParameters()
{
}


