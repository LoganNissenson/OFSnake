#include "Snake.h"
#include "ofGraphics.h"
#include <cstdlib>
#include <stdio.h>
#include <iostream>


Snake::Snake(int startLength, double initialHeadX, double initialHeadY)
{

	// Initializing the initial direction of the snake
	x_direction = 1;	// Where 1 means going to the right
	y_direction = 0;	// Where 0 means no y-direction movement

	// Starting Color Value
	int initialHeadColor[3] = {0,0,255};		// Setting the Initial head Color to blue

	// Creating the head of the snake
	head.x = initialHeadX;
	head.y = initialHeadY;
	head.setColor(initialHeadColor);

	// Creating the body of the snake
	body.push_back(head);
	for(int i=1; i <= (startLength-1); i++){
		BodySegment newSegment(i*(BodySegment::WIDTH) + head.x, head.y, initialHeadColor);
		body.push_back(newSegment);
	}
}


void Snake::eat(FoodMorsel foodJustEaten)
{
	// The coordinates of the tail of the snake must be obtained in order to a segment to the end
	int tailIndex = body.size() - 1;
	BodySegment tail = body[tailIndex];

	// Creating the new segment that will be added to the snake
	int newSegmentColor[3] = {foodJustEaten.getRedColorValue(), foodJustEaten.getGreenColorValue(), foodJustEaten.getBlueColorValue()};
	BodySegment newBodySegment(tail.x + x_direction*BodySegment::WIDTH, tail.y + y_direction*BodySegment::HEIGHT, newSegmentColor);


	//Adding the new body segment to the snake
	body.push_back(newBodySegment);
}


int Snake::getBodyLength(){
	return body.size();
}

void Snake::setXDirection(int new_x_direction){
	if(new_x_direction >= -1 && new_x_direction <= 1)
		x_direction = new_x_direction;
	else
		std::cerr << "X-direction value out of range" << endl;
}

void Snake::setYDirection(int new_y_direction){
	if(new_y_direction >= -1 && new_y_direction <= 1)
		y_direction = new_y_direction;
	else
		std::cerr << "Y-direction value out of range" << endl;
}

void Snake::move(){
	vector<BodySegment> oldSnakeBody = body;

	// Moving the head to the new position that is determined by the direction that the snake is moving
	body[0].x = body[0].x + BodySegment::WIDTH*x_direction;
	body[0].y = body[0].y + BodySegment::HEIGHT*y_direction;

	// Updating the rest of the body
	for(int i=0; i < body.size() - 1; i++){
		body[i+1].x = oldSnakeBody[i].x;
		body[i+1].y = oldSnakeBody[i].y;
	}
}

BodySegment Snake::getSegmentAt(int index){
	if(index >= 0 && index <= (body.size() - 1))
		return body[index];
	else
		std::cerr << "Index value out of the range of the snake's body";
}

int Snake::getXDirection(){
	return x_direction;
}

int Snake::getYDirection(){
	return y_direction;
}

bool Snake::isOutOfBounds(int screenWidth, int screenHeight){
	BodySegment head = body[0];
	if(y_direction){
		if( head.y >= screenHeight || head.y <= 0)
			return true;
		else if((head.x + head.width) >= screenWidth || (head.x <= 0))
			return true;
		else
			return false;
	}
	else{
		if(head.x >= screenWidth || head.x <= 0){
			return true;
		}
		else if((head.y + head.height) >= screenHeight || (head.y <= 0)){
			return true;
		}
		else{
			return false;
		}
	}

}
