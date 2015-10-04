#include "OrbitLane.h"
#include "GameEngine.h"
OrbitLane::OrbitLane(GLfloat _radius)
{
	radius = _radius;
	GameEngine::AddRenderableObject(this);
}

OrbitLane::~OrbitLane()
{
}
double PI = 3.1415926535897f;
int numPoints = 100;
void OrbitLane::Render()
{
	glRotatef(90, 1.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_STRIP);

	for (int i = 0; i < numPoints; i++)
	{
		double angle = i * (2.2 * PI / numPoints);
		GLfloat x = (GLfloat)cos(angle)*radius;
		GLfloat y = (GLfloat)sin(angle)*radius;
		glVertex2f(x, y);
	}

	glEnd();
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	glFlush();
}

void OrbitLane::Update()
{

}