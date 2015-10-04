#include "GameWorld.h"
#include "GameEngine.h"

using namespace std;

GameWorld::GameWorld()
{
	// Create the background for the universe
	mUniverseBackground = make_shared<UniverseBackground>(1000);

	// Create planets
	mSun = make_shared<Sun>();
	mMercury = make_shared<Mercury>();
	mVenus = make_shared<Venus>();
	mEarth = make_shared<Earth>();
	mMars = make_shared<Mars>();
	mJupiter = make_shared<Jupiter>();
	mSaturn = make_shared<Saturn>();
	mUranus = make_shared<Uranus>();
	mNeptune = make_shared<Neptune>();
	mPluto = make_shared<Pluto>();

	// Create orbital lanes
	mOrbitLane1= make_shared<OrbitLane>(100.0f);
	mOrbitLane2 = make_shared<OrbitLane>(200.0f);
	mOrbitLane3 = make_shared<OrbitLane>(300.0f);
	mOrbitLane4 = make_shared<OrbitLane>(400.0f);
	mOrbitLane5 = make_shared<OrbitLane>(500.0f);
	mOrbitLane6 = make_shared<OrbitLane>(600.0f);
	mOrbitLane7 = make_shared<OrbitLane>(700.0f);
	mOrbitLane8 = make_shared<OrbitLane>(800.0f);
	mOrbitLane9 = make_shared<OrbitLane>(900.0f);
}

GameWorld::~GameWorld()
{
}