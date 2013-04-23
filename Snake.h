#pragma once
#include <string>
#include <vector>
#include "BodySegment.h"
#include "FoodMorsel.h"
#include "ofGraphics.h"

using namespace std;

class Snake
{
public:
  BodySegment head;
	
	Snake(int startLength, double initialHeadX, double initialHeadY);

	void eat(FoodMorsel foodJustEaten);
	void setXDirection(int newXDirection);
	void setYDirection(int newYDirection);
	int getYDirection();
	int getXDirection();
	void move();
	BodySegment getSegmentAt(int index);
	int getBodyLength();
	bool isOutOfBounds(int screenWidth, int screenHeight);

private:
	int x_direction;			// Varies between 1, and -1
	int y_direction;			// Varies between 1, and -1
	vector<BodySegment> body;	
};

