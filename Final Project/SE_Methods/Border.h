#pragma once
#include "Graphics.h"

class Border
{
public:
	Border() {};
	virtual void createBorder(Graphics& graphics, short left, short top, short width, short height) = 0;
	~Border() {};
};

class SingleBorder : public Border
{
public:
	SingleBorder() {};
	void createBorder(Graphics& graphics, short left, short top, short width, short height);
	~SingleBorder() {};
};

class DoubleBorder : public Border
{
public:
	DoubleBorder() {};
	void createBorder(Graphics& graphics, short left, short top, short width, short height);
	~DoubleBorder() {};
};