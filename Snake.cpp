#include "Snake.h"
#include <cstdlib>


Snake::Snake(int startLength, double initialHeadX, double initialHeadY)
{
  length = startLength;

	// Creating the head of the snake
	head.push_back(initialHeadX);
	head.push_back(initialHeadY);

	// Creating the body of the snake
	body.push_back(head);


	

}


void Snake::grow()
{
	
}
