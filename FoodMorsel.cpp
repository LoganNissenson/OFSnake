#include "FoodMorsel.h"
#include <time.h>
#include "stdlib.h"


FoodMorsel::FoodMorsel()
{
  // Initializing the width and height, which are the width and height
	width = 20;
	height = 20;

	// Initializing the random seed for the relocated function
	srand(time(NULL));

	// Initalizing the first color
	color[0] = 0;
	color[1] = 255;
	color[2] = 0;
	
}

int FoodMorsel::getRedColorValue(){
	return color[0];
}

int FoodMorsel::getGreenColorValue(){
	return color[1];
}

int FoodMorsel::getBlueColorValue(){
	return color[2];
}

// Everytime the snake eats a food morsel on the screen, the food morsel has to relocate
// The reolocate function changes the location of the food, and gives it a new color
void FoodMorsel::relocate(int screen_width, int screen_height){
	// Creating a new random color
	for(int i=0; i < 3; i++){
		color[i] = rand() % 255;
	}

	// Giving the food morsel a new random location
	x = rand() % (screen_width - int(width));
	y = rand() % (screen_height - int(height)); 
}

