#pragma once
#include "Planet.h"



class Earth : 
	public Planet
{
private:
	GLfloat planetOrbitAngle = 0.0f;
	GLfloat sunOrbitAngle = 0.0f;

public:
	Earth();
	~Earth();
	bool Render() override;
};

