#include "UniverseCameraParameters.h"




UniverseCameraParameters::UniverseCameraParameters()
{
	 // camA = 20;
	 // camB = -120;
	 // camC = -60;

	 camA = 10;
	 camB = 10;
	 camC = -120;

	  cameraViewAngle = 0.0f;
	  universeLoaded = false;

	  animate = false;
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


