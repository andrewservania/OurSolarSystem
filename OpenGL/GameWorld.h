#pragma once

#include "Mercury.h"
#include "Venus.h"
#include "Earth.h"
#include "Mars.h"
#include "Jupiter.h"
#include "Saturn.h"
#include "Uranus.h"
#include "Neptune.h"
#include "Pluto.h"
#include "Sun.h"
#include "UniverseBackground.h"
#include "OrbitLane.h"

#include <memory>

class GameWorld
{
private:

	std::shared_ptr<UniverseBackground> mUniverseBackground;
	std::shared_ptr<Sun> mSun;
	std::shared_ptr<Mercury> mMercury;
	std::shared_ptr<Venus> mVenus;
	std::shared_ptr<Earth> mEarth;
	std::shared_ptr<Mars> mMars;
	std::shared_ptr<Jupiter> mJupiter;
	std::shared_ptr<Saturn> mSaturn;
	std::shared_ptr<Uranus> mUranus;
	std::shared_ptr<Neptune> mNeptune;
	std::shared_ptr<Pluto> mPluto;

	//Planet lanes
	std::shared_ptr<OrbitLane> mOrbitLane1;
	std::shared_ptr<OrbitLane> mOrbitLane2;
	std::shared_ptr<OrbitLane> mOrbitLane3;
	std::shared_ptr<OrbitLane> mOrbitLane4;
	std::shared_ptr<OrbitLane> mOrbitLane5;
	std::shared_ptr<OrbitLane> mOrbitLane6;
	std::shared_ptr<OrbitLane> mOrbitLane7;
	std::shared_ptr<OrbitLane> mOrbitLane8;
	std::shared_ptr<OrbitLane> mOrbitLane9;

public:
	GameWorld();
	~GameWorld();
};
