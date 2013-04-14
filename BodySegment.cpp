#include "BodySegment.h"
#include "ofGraphics.h"
#include <stdio.h>
#include <iostream>

const double BodySegment::WIDTH = 20;
const double BodySegment::HEIGHT = 20;

BodySegment::BodySegment(){
}


BodySegment::BodySegment(double x_coord, double y_coord, int segmentColor[3])
{
	width = WIDTH;
	height = HEIGHT;
	x = x_coord;
	y = y_coord;
	for(int i=0; i < 3; i++){
		color[i] = segmentColor[i];
	};
}

void BodySegment::draw(){
	ofSetColor(color[0], color[1], color[2]);
	ofRect(x, y, width, height);
}


int BodySegment::getRedValue(){
	return color[0];
}

int BodySegment::getGreenValue(){
	return color[1];
}

int BodySegment::getBlueValue(){
	return color[2];
}

void BodySegment::setRedValue(int colorNum){
	if(colorNum >= 0 && colorNum <= 255)
		color[0] = colorNum;
}

void BodySegment::setGreenValue(int colorNum){
	if(colorNum >= 0 && colorNum <= 255)
		color[1] = colorNum;
}

void BodySegment::setBlueValue(int colorNum){
	if(colorNum >= 0 && colorNum <= 255)
		color[2] = colorNum;
}

void BodySegment::setColor(int colorArray[3]){
	bool colorValuesAreValid = false;
	for(int i=0; i < 3; i++){
		if(colorArray[i] >= 0 && colorArray[i] <= 255){
			colorValuesAreValid = true;
		}
	}
	if(colorValuesAreValid){
		for(int i=0; i < 3; i++){
			color[i] = colorArray[i];
		}
	}
}

bool BodySegment::intersects(const ofRectangle& rect){
	return (((x - width) < (rect.x + rect.width) && (x + width) > (rect.x - rect.width)) &&
            ((y + height) < (rect.y + rect.height) && (y-height) > (rect.y - rect.height)));
}
