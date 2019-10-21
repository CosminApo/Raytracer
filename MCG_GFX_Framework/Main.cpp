
#include <cmath>
#include "MCG_GFX_Lib.h"
#include "Camera.h"
#include "Ray.h"
#include "Tracer.h"
#include "Geometry.h"
#include <windows.h>
#include <iostream>
#include "UTILITY.h"
#include <stdlib.h>

const int xResolution = 640;
const int yResolution = 480;

int Raytracer();
void drawLine(glm::fvec2 _pixelPosition, glm::fvec2 _pixelPosition2);
void drawSquare(glm::fvec2 _origin);
void drawTriangle(glm::fvec2 _origin);
void drawCircle();
void demoMode();

int main(int argc, char *argv[])
{
	// Variable for storing window dimensions
	glm::fvec2 windowSize(xResolution, yResolution);



#pragma region DefaultStuff
	// Call MCG::Init to initialise and create your window
	// Tell it what size you want the window to be
	if (!MCG::Init(windowSize))
	{
		// We must check if something went wrong
		// (this is very unlikely)
		return -1;
	}

	// Sets every pixel to the same colour
	// parameters are RGBA, numbers are from 0 to 255





	//// Preparing a position to draw a pixel
	//glm::ivec2 pixelPosition = windowSize / 2;

	//// Preparing a colour to draw
	//// Colours are RGB, each value ranges between 0 and 255
	//glm::ivec3 pixelColour( 255, 0, 0 );


	//// Draws a single pixel at the specified coordinates in the specified colour!
	//MCG::DrawPixel( pixelPosition, pixelColour );

	// Do any other DrawPixel calls here
	// ...

	// Displays drawing to screen and holds until user closes window
	// You must call this after all your drawing calls
	// Program will exit after this line
	MCG::SetBackground(glm::ivec3(0, 0, 0));
#pragma endregion
	bool exit = false;

	do
	{
		system("CLS");
		int choice = 0;
		std::cout << "-------------- MENU  --------------";
		std::cout << "\nPlease select one of the following options: ";
		std::cout << "\n1. Draw a line";
		std::cout << "\n2. Draw a square";
		std::cout << "\n3. Draw a triangle";
		std::cout << "\n4. Draw a circle";
		std::cout << "\n5. Draw a sphere using Raytracing ";
		std::cout << "\n6. Demo mode (all shapes drawn one after another) ";
		std::cout << "\n7. Exit ";

		std::cout << "\n Your choice> ";
		std::cin >> choice;
		MCG::SetBackground(glm::ivec3(0, 0, 0)); //resets the screen to black
		MCG::ProcessFrame(); //display the current frame

		if (choice > 0 && choice < 7)
			std::cout << "\nLoading...";

		switch (choice)
		{
		case 1:
			drawLine(glm::fvec2(xResolution / 2, yResolution / 2), glm::fvec2(xResolution / 2+100, yResolution / 2-100));
			break;
		case 2:
			drawSquare(glm::fvec2(xResolution / 2, yResolution / 2));
			break;
		case 3:
			drawTriangle(glm::fvec2(xResolution / 2, yResolution / 2));
			break;
		case 4:
			drawCircle();
			break;
		case 5:
			Raytracer();
			break;
		case 6:
			demoMode();
			break;
		case 7:
			exit = true;
			break;
		default:
			std::cout << "\nInvalid input\n";
			break;
		}


		MCG::ProcessFrame();
		Sleep(1500);

	} while (!exit);


	return 0;


#pragma region Animation

	// Advanced access - comment out the above DrawPixel and MCG::ShowAndHold lines, then uncomment the following:

	/*
	// Variable to keep track of time
	float timer = 0.0f;

	// This is our game loop
	// It will run until the user presses 'escape' or closes the window
	while( MCG::ProcessFrame() )
	{
		// Set every pixel to the same colour
		MCG::SetBackground( glm::ivec3( 0, 0, 0 ) );

		// Change our pixel's X coordinate according to time
		pixelPosition.x = (windowSize.x / 2) + (int)(sin(timer) * 100.0f);
		// Update our time variable
		timer += 1.0f / 60.0f;

		// Draw the pixel to the screen
		MCG::DrawPixel( pixelPosition, pixelColour );

	}

	return 0;
	*/
#pragma endregion
}

int Raytracer()
{
	Camera myCam;
	Tracer myTracer;
	Ray myRay;
	Sphere mySphere;
	Geometry::sphereIntersection myIntersection;
	mySphere.origin = { 0,0,-10 };
	mySphere.radius = 2.0;
	myTracer.allSpheres.push_back(mySphere);
	glm::fvec2 pixelPosition(0, 0);
	glm::fvec3 pixelColour(0, 0, 0);
	for (int i = 0; i < yResolution; i++) //for each pixel on the screen
	{
		for (int j = 0; j < xResolution; j++)
		{
			pixelPosition = { i,j };
			myRay = myCam.getRay(pixelPosition); //generate ray
			pixelColour = myTracer.getColour(myRay, &myIntersection); //trace the ray to get the colour
			MCG::DrawPixel(pixelPosition, pixelColour); //display result
		}
	}
	std::cout << "\nDrawing Complete";
	return 0;
}

void drawLine(glm::fvec2 _pixelPosition, glm::fvec2 _pixelPosition2)
{
		
	glm::fvec2 pixelPosition = _pixelPosition;
	glm::fvec2 pixelPosition2 = _pixelPosition2;
	glm::fvec3 pixelColour(255, 0, 0);

	while (pixelPosition != pixelPosition2)
	{
		MCG::DrawPixel(pixelPosition, pixelColour); //draws a pixel to the screen

		if (pixelPosition.x < pixelPosition2.x)
			pixelPosition.x++;
		
		if (pixelPosition.x > pixelPosition2.x)
			pixelPosition.x--;
		
		if (pixelPosition.y < pixelPosition2.y)
			pixelPosition.y++;
		
		if (pixelPosition.y > pixelPosition2.y)
			pixelPosition.y--;
		

	}
}
void drawSquare(glm::fvec2 _origin)
{ 
	glm::fvec2 origin = _origin; //starting point
	glm::fvec3 pixelColour(255, 0, 0);
	glm::fvec2 endpoint = { 0,0 };
	int length = 200;

	for (int i = 0; i < length; i++) //draw multiple lines from an incrementing Y position
	{
		origin.y++;
		endpoint = { origin.x + length,origin.y };
		drawLine(origin, endpoint);
	}
}
void drawTriangle(glm::fvec2 _origin)
{
	glm::fvec2 pixelPosition = _origin;
	glm::fvec2 endPoint = { 0,0 };
	glm::fvec3 pixelColour(255, 0, 0);
	int width = 200;
	int height = 200;

	for (int i = 0; i < height; i++) //iterate through each Y pos
	{
		width--; //decrease the length of the line
		pixelPosition.y--; //move the Y pos
	
		endPoint = pixelPosition; 
		endPoint.x += width; //increment the X coord by the width of the line
		drawLine(pixelPosition, endPoint);

	}
}

void drawCircle()
{
	glm::fvec2 pixelPosition = { 0,0 };
	glm::fvec3 pixelColour(255, 0, 0);

	double angle = 0;
	double xorigin = xResolution / 2; //centre of the screen
	double yorigin = yResolution / 2;
	double radius = 200;

	double z = sin(angle)* radius;
	double y = radius + z;
	double x = 0;
	double temp = radius;

	for (int j = 0; j < temp; j++)
	{
		radius -= 1;
		for (double i = 0; i < 360; i += 0.1) //for each point in a circle's circumference
		{
			angle = i;
			angle = UTILITY::degreesToRad(angle);
			z = sin(angle)* radius; //sohcahtoa rule
			y = yorigin + z; //get y pos
			x = xorigin + cos(angle)*radius; //get x pos
			pixelPosition = { x,y };
			MCG::DrawPixel(pixelPosition, pixelColour);


		}
	}

}
void demoMode()
{
	MCG::SetBackground(glm::ivec3(0, 0, 0));
	std::cout << "\nDrawing Line...";
	drawLine(glm::fvec2(xResolution / 2, yResolution / 2), glm::fvec2(xResolution / 2 + 100, yResolution / 2 - 100));
	MCG::ProcessFrame();
	std::cout << "\nComplete!";
	Sleep(2500);

	MCG::SetBackground(glm::ivec3(0, 0, 0));
	std::cout << "\nDrawing Square...";
	drawSquare(glm::fvec2(xResolution / 2, yResolution / 2));
	MCG::ProcessFrame();
	std::cout << "\nComplete!";
	Sleep(2500);

	MCG::SetBackground(glm::ivec3(0, 0, 0));
	std::cout << "\nDrawing Triangle...";
	drawTriangle(glm::fvec2(xResolution / 2, yResolution / 2));
	MCG::ProcessFrame();
	std::cout << "\nComplete!";
	Sleep(2500);

	MCG::SetBackground(glm::ivec3(0, 0, 0));
	std::cout << "\nDrawing Circle...";
	drawCircle();
	MCG::ProcessFrame();
	std::cout << "\nComplete!";
	Sleep(2500);

	MCG::SetBackground(glm::ivec3(0, 0, 0));
	std::cout << "\nDrawing Sphere...";
	Raytracer();
}
