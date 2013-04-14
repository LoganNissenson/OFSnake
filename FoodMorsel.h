#pragma once
#include "ofGraphics.h"

class FoodMorsel: public ofRectangle
{
public:

  FoodMorsel();
	int getRedColorValue();
	int getGreenColorValue();
	int getBlueColorValue();
	void relocate(int screen_width, int screen_height);
private:
	int color[3];

};

