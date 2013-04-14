#pragma once
#include "ofGraphics.h"

class BodySegment: public ofRectangle
{
public:
	static const double BodySegment::WIDTH;
	static const double BodySegment::HEIGHT;

	int getRedValue();
	int getGreenValue();
	int getBlueValue();
	void setColor(int colorArray[3]);
	void setRedValue(int color);
	void setGreenValue(int color);
	void setBlueValue(int color);
	bool intersects(const ofRectangle& rect);
	void draw();

	BodySegment();
	BodySegment(double x, double y, int colorArray[3]);
private:
	int color[3];

};


