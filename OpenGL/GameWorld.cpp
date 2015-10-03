#include "GameWorld.h"
#include "GameEngine.h"

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

	// Set their sizes
	mMercury->SetSize(5);
	mVenus->SetSize(6);
	mEarth->SetSize(40);
	mMars->SetSize(10);
	mJupiter->SetSize(27);
	mSaturn->SetSize(23);
	mUranus->SetSize(19);
	mNeptune->SetSize(18);
	mPluto->SetSize(3);

	// Set their locations
	mMercury->SetPosition(100, 0, 0);
	mVenus->SetPosition(200, 0, 0);
	mEarth->SetPosition(300, 0, 0);
	mMars->SetPosition(400, 0, 0);
	mJupiter->SetPosition(500, 0, 0);
	mSaturn->SetPosition(600, 0, 0);
	mUranus->SetPosition(700, 0, 0);
	mNeptune->SetPosition(800, 0, 0);
	mPluto->SetPosition(900, 0, 0);

	// Add planets as render-able objects
	GameEngine::AddRenderableObject(mUniverseBackground);
	GameEngine::AddRenderableObject(mSun);
	GameEngine::AddRenderableObject(mMercury);
	GameEngine::AddRenderableObject(mVenus);
	GameEngine::AddRenderableObject(mEarth);
	GameEngine::AddRenderableObject(mMars);
	GameEngine::AddRenderableObject(mJupiter);
	GameEngine::AddRenderableObject(mSaturn);
	GameEngine::AddRenderableObject(mUranus);
	GameEngine::AddRenderableObject(mNeptune);
	GameEngine::AddRenderableObject(mPluto);


	// Create orbital lanes
	mOrbitLane1 = make_shared<OrbitLane>();
	mOrbitLane2 = make_shared<OrbitLane>();
	mOrbitLane3 = make_shared<OrbitLane>();
	mOrbitLane4 = make_shared<OrbitLane>();
	mOrbitLane5 = make_shared<OrbitLane>();
	mOrbitLane6 = make_shared<OrbitLane>();
	mOrbitLane7 = make_shared<OrbitLane>();
	mOrbitLane8 = make_shared<OrbitLane>();
	mOrbitLane9 = make_shared<OrbitLane>();

	// Don't forget to add the lanes as render-able objects!

}


GameWorld::~GameWorld()
{
}
