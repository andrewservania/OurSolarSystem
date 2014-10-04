#pragma once
class UniverseCameraParameters
{
public:
	static float camA;
	static float camB;
	static float camC;
	static float cameraViewAngle;
	static bool universeLoaded;

	static bool animate;
	static bool visibility;
	static float colorValue;
	static bool light;
	static bool resetView;

	static int lightPosX;
	static int lightPosY;
	static int lightPosZ;

	UniverseCameraParameters();
	~UniverseCameraParameters();
	
};

