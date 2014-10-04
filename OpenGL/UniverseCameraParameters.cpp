#include "UniverseCameraParameters.h"



 float UniverseCameraParameters::camA = 20;
 float UniverseCameraParameters::camB = -120;
 float UniverseCameraParameters::camC = -60;
 float UniverseCameraParameters::cameraViewAngle = 10.0f;
 bool UniverseCameraParameters::universeLoaded = false;

 bool UniverseCameraParameters::animate = true;
 bool UniverseCameraParameters::visibility = true;
 float UniverseCameraParameters::colorValue = 0.0f;
 bool UniverseCameraParameters::light = true;
 bool UniverseCameraParameters::resetView = false;

 int UniverseCameraParameters::lightPosX = 1;
 int UniverseCameraParameters::lightPosY = 1;
 int UniverseCameraParameters::lightPosZ = 1;

UniverseCameraParameters::UniverseCameraParameters()
{

}


UniverseCameraParameters::~UniverseCameraParameters()
{
}


