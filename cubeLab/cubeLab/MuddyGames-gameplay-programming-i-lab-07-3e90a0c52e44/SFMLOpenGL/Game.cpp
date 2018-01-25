#include "Game.h"

bool updatable = false;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);

	cubePoints[0] = {1,1,1};
	cubePoints[1] = { -1,1,1 };
	cubePoints[2] = { 1,-1,1 };
	cubePoints[3] = { -1, -1,1 };
	cubePoints[4] = { 1, 1,-1 };
	cubePoints[5] = { -1, 1,-1 };
	cubePoints[6] = { 1,-1,-1 };
	cubePoints[7] = { -1,-1,-1 };

}

Game::~Game(){}

void Game::run()
{
	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}
}

void Game::initialize()
{
	isRunning = true;


	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations


	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	
}

void Game::update()
{
	//rotations
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		for (int i = 0; i < 8; i++)
		{
			cubePoints[i] = matrix.RotationX(0.1) * cubePoints[i];
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		for (int i = 0; i < 8; i++)
		{
			cubePoints[i] = matrix.RotationY(0.1) * cubePoints[i];
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		for (int i = 0; i < 8; i++)
		{
			cubePoints[i] = matrix.RotationZ(0.1) * cubePoints[i];
		}
	}

	// scaling
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		for (int i = 0; i < 8; i++)
		{
			cubePoints[i] = matrix.Scale3D(101) * cubePoints[i];
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		for (int i = 0; i < 8; i++)
		{
			cubePoints[i] = matrix.Scale3D(99) * cubePoints[i];
		}
	}

	cout << "Update" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -8.0f);						// Translate Screen 

	glBegin(GL_QUADS);
	{
		glColor3f(0.0f, 1.0f, 0.0f);						
		glVertex3f(cubePoints[4].ReturnX(), cubePoints[4].ReturnY(), cubePoints[4].ReturnZ());					// Top Right Of The Quad (Top)
		glVertex3f(cubePoints[5].ReturnX(), cubePoints[5].ReturnY(), cubePoints[5].ReturnZ());					// Top Left Of The Quad (Top)
		glVertex3f(cubePoints[1].ReturnX(), cubePoints[1].ReturnY(), cubePoints[1].ReturnZ());					// Bottom Left Of The Quad (Top)
		glVertex3f(cubePoints[0].ReturnX(), cubePoints[0].ReturnY(), cubePoints[0].ReturnZ());					// Bottom Right Of The Quad (Top)

		glColor3f(1.0f, 0.5f, 0.0f);						
		glVertex3f(cubePoints[2].ReturnX(), cubePoints[2].ReturnY(), cubePoints[2].ReturnZ());					// Top Right Of The Quad (Bottom)
		glVertex3f(cubePoints[3].ReturnX(), cubePoints[3].ReturnY(), cubePoints[3].ReturnZ());					// Top Left Of The Quad (Bottom)
		glVertex3f(cubePoints[7].ReturnX(), cubePoints[7].ReturnY(), cubePoints[7].ReturnZ());					// Bottom Left Of The Quad (Bottom)
		glVertex3f(cubePoints[6].ReturnX(), cubePoints[6].ReturnY(), cubePoints[6].ReturnZ());					// Bottom Right Of The Quad (Bottom)

		glColor3f(1.0f, 0.0f, 0.0f);						
		glVertex3f(cubePoints[0].ReturnX(), cubePoints[0].ReturnY(), cubePoints[0].ReturnZ());					// Top Right Of The Quad (Front)
		glVertex3f(cubePoints[1].ReturnX(), cubePoints[1].ReturnY(), cubePoints[1].ReturnZ());					// Top Left Of The Quad (Front)
		glVertex3f(cubePoints[3].ReturnX(), cubePoints[3].ReturnY(), cubePoints[3].ReturnZ());					// Bottom Left Of The Quad (Front)
		glVertex3f(cubePoints[2].ReturnX(), cubePoints[2].ReturnY(), cubePoints[2].ReturnZ());					// Bottom Right Of The Quad (Front)

		glColor3f(1.0f, 1.0f, 0.0f);						
		glVertex3f(cubePoints[6].ReturnX(), cubePoints[6].ReturnY(), cubePoints[6].ReturnZ());					// Top Right Of The Quad (Back)
		glVertex3f(cubePoints[7].ReturnX(), cubePoints[7].ReturnY(), cubePoints[7].ReturnZ());					// Top Left Of The Quad (Back)
		glVertex3f(cubePoints[5].ReturnX(), cubePoints[5].ReturnY(), cubePoints[5].ReturnZ());					// Bottom Left Of The Quad (Back)
		glVertex3f(cubePoints[4].ReturnX(), cubePoints[4].ReturnY(), cubePoints[4].ReturnZ());					// Bottom Right Of The Quad (Back)

		glColor3f(0.0f, 0.0f, 1.0f);						
		glVertex3f(cubePoints[1].ReturnX(), cubePoints[1].ReturnY(), cubePoints[1].ReturnZ());					// Top Right Of The Quad (Left)
		glVertex3f(cubePoints[5].ReturnX(), cubePoints[5].ReturnY(), cubePoints[5].ReturnZ());					// Top Left Of The Quad (Left)
		glVertex3f(cubePoints[7].ReturnX(), cubePoints[7].ReturnY(), cubePoints[7].ReturnZ());					// Bottom Left Of The Quad (Left)
		glVertex3f(cubePoints[3].ReturnX(), cubePoints[3].ReturnY(), cubePoints[3].ReturnZ());					// Bottom Right Of The Quad (Left)

		glColor3f(1.0f, 0.0f, 1.0f);						
		glVertex3f(cubePoints[4].ReturnX(), cubePoints[4].ReturnY(), cubePoints[4].ReturnZ());					// Top Right Of The Quad (Right)
		glVertex3f(cubePoints[0].ReturnX(), cubePoints[0].ReturnY(), cubePoints[0].ReturnZ());					// Top Left Of The Quad (Right)
		glVertex3f(cubePoints[2].ReturnX(), cubePoints[2].ReturnY(), cubePoints[2].ReturnZ());					// Bottom Left Of The Quad (Right)
		glVertex3f(cubePoints[6].ReturnX(), cubePoints[6].ReturnY(), cubePoints[6].ReturnZ());					// Bottom Right Of The Quad (Right)
	}
	glEnd();
	
	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;

}

