#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "Vector3.h"
#include "Matrix3.h"

//@author Oisin Wilson
//@login C00213826
//@description: 
// Demo of 3D library on a cube
//@Known Bugs:
// no known bugs

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	GLuint index;
	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
	
	Vector3D cubePoints[8];

	Matrix3 matrix;

	bool rotateSwap;

};