#include "Camera.h"




Camera::Camera()
{
	 // camA = 20;
	 // camB = -120;
	 // camC = -60;

	 camA = 0;
	 camB = 0;
	 camC = -336;

	  cameraViewAngle = -85.0f;
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


Camera::~Camera()
{
}


