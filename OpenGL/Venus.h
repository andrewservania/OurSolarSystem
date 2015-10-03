#pragma once
#include "Planet.h"
class Venus :
	public Planet
{
private:
	GLfloat planetOrbitAngle = 0.0f;
	GLfloat sunOrbitAngle = 0.0f;
public:
	Venus();
	~Venus();
	void Render() override;
	void Update() override;
};
