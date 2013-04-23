#include "SnakeGame.h"
#include "Snake.h"
#include "FoodMorsel.h"
#include <string.h>
#include <stdio.h>
#include <iostream>

// Game constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

// Game variables
FoodMorsel testFood;
Snake testSnake(5,50,0);
int gameScore = 0;
string game_state;

// Function prototypes
void drawSnake(Snake snake);
bool snakeOverFood(Snake &snake, FoodMorsel &food);
void drawFood(FoodMorsel food);
bool snakeIsColliding(Snake snake);

//--------------------------------------------------------------
void SnakeGame::setup(){
  // Initializing an initial color and location for the food
	testFood.relocate(SCREEN_WIDTH, SCREEN_HEIGHT);
	gameScore = 0;
	game_state = "PLAYING";	// The initial state is set as playing when the program begings
}

//--------------------------------------------------------------
void SnakeGame::update(){
	if (game_state == "PLAYING"){
		testSnake.move();
		if(snakeOverFood(testSnake, testFood)){
			testSnake.eat(testFood);
			// Function call to update score should be inserted here
			testFood.relocate(SCREEN_WIDTH, SCREEN_HEIGHT);
		}
		if(snakeIsColliding(testSnake))
			game_state = "OVER";
	}
}

//--------------------------------------------------------------
void SnakeGame::draw(){
	// The snake will always be drawn in the background, even if some sort of paused or game over screen
	// is covering part of it up
	drawSnake(testSnake);
	drawFood(testFood);

	if(game_state == "OVER"){
		// Code to draw a game over screen
	}

	if(game_state == "PAUSED"){
		// Code to draw a paused screen, prompting the user to press a button to un-pause the screen
	}
}

//--------------------------------------------------------------
void SnakeGame::keyPressed(int key){
	// Move up if currently moving in a horizontal direction
	if(key == OF_KEY_UP ){
		if(testSnake.getXDirection()){
			testSnake.setYDirection(-1);
			testSnake.setXDirection(0);
		}
	}
	// Move down if currently moving in a horizontal direction
	if(key == OF_KEY_DOWN){
		if(testSnake.getXDirection()){
			testSnake.setYDirection(1);
			testSnake.setXDirection(0);
		}
	}
	// Move right if currently moving in a vertical direction
	if(key == OF_KEY_RIGHT){
		if(testSnake.getYDirection()){
			testSnake.setXDirection(1);
			testSnake.setYDirection(0);
		}
	}
	// Move left if currently moving in a vertical direction
	if(key == OF_KEY_LEFT){
		if(testSnake.getYDirection()){
			testSnake.setXDirection(-1);
			testSnake.setYDirection(0);
		}
	}

	if(key == 'e'){
		game_state = "OVER";	// Test button to see what happens when the "OVER" state is entered
	}
}

//--------------------------------------------------------------
void SnakeGame::keyReleased(int key){

}

//--------------------------------------------------------------
void SnakeGame::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void SnakeGame::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void SnakeGame::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void SnakeGame::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void SnakeGame::windowResized(int w, int h){

}




void drawSnake(Snake snake){
	for(int i= 0; i < snake.getBodyLength(); i++){
		ofSetColor(snake.getSegmentAt(i).getRedValue(), snake.getSegmentAt(i).getGreenValue(), snake.getSegmentAt(i).getBlueValue());
		ofRect(snake.getSegmentAt(i).x, snake.getSegmentAt(i).y, snake.getSegmentAt(i).WIDTH, snake.getSegmentAt(i).HEIGHT);
	}
}

bool snakeOverFood(Snake &snake, FoodMorsel &food){
	BodySegment snakeHead = snake.getSegmentAt(0);
	return snakeHead.intersects(food);	// Checking to see if the snake head is on top of the food
}

void drawFood(FoodMorsel food){
	ofSetColor(food.getRedColorValue(), food.getGreenColorValue(), food.getBlueColorValue());
	ofRect(food.x, food.y, food.width, food.height);
}

// Checks to see if the head of the snake is colliding with the boundry of the screen or with itself
// returns true if the snake is colliding with something it shouldn't be
bool snakeIsColliding(Snake &snake){
	bool isSnakeColliding = false;
	// Storing the head of the snake in variable
	BodySegment snakeHead = snake.getSegmentAt(0);
	isSnakeColliding = testSnake.isOutOfBounds(SCREEN_WIDTH, SCREEN_HEIGHT);	// If the snake is out of bounds, then the function returns true
	for(int i=2; i < snake.getBodyLength() - 2; i++){
		if(snakeHead.intersects(snake.getSegmentAt(i))){
			isSnakeColliding = true;
		}
	}
	return isSnakeColliding;	// Default set to false, the code will return true if there is a collision
}

// Draws the current score to the screen
void drawScore(){
	// Converting the integer game score to a string
	string stringScore;
	ostringstream convert;
	convert << gameScore;
	stringScore = convert.str();

	// Drawing the string to the screen using the ofDrawBitmap string function
	ofSetColor(255, 211, 155);	// Setting the color to a nice tan hue
	float scoreStringXCoord = SCREEN_WIDTH/10;
	float scoreStringYCoord = SCREEN_HEIGHT/7;
	scoreFont.drawString(stringScore, scoreStringXCoord, scoreStringYCoord);

}

// Draws a pause screen
void drawPauseScreen(){
	ofSetColor(139, 26, 26);	// Setting the pause text to a firebrick color
	float pauseStringXCoord = (SCREEN_WIDTH/2) - 100;
	float pauseStringYCoord = SCREEN_HEIGHT/2;
	pausedFont.drawString("Game Paused", pauseStringXCoord, pauseStringYCoord);
	pausedFont.setLineHeight(10);
	pausedFont.drawString("Press p to unpause", SCREEN_WIDTH/4, pauseStringYCoord + 90);
}


