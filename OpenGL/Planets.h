#pragma once 

using namespace std;

	class Planets
	{
		

	public :
	    static bool showOrbitalLanes;

		static void drawOrbit(float Radius, int numPoints, bool visible, float customV);

		static void CreateMercury(float solarSystemRotation);

		static void CreateVenus(float solarSystemRotation);

		static void CreatePlanetEarth(float solarSystemRotation);

		static void CreateMars(float solarSystemRotation);

		static void CreateJupiter(float solarSystemRotation);

		static void CreateSaturn(float solarSystemRotation);

		static void CreateUranus(float solarSystemRotation);

		static void CreateNeptunus(float solarSystemRotation);

		static void CreatePluto(float solarSystemRotation);

		static void LoadPlanetImages(const char* fileName);
	
		static void createTexturedPlanet();

	
	
	};

