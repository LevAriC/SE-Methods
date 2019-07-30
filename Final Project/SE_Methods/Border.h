#pragma once
#include "Graphics.h"

class Border
{
public:
	Border() {};
	virtual void createBorder(Graphics& graphics, short left, short top, short width, short height) = 0;
};

class NoBorder : public Border
{
public:
	NoBorder() {};
	void createBorder(Graphics& graphics, short left, short top, short width, short height) {};
};

class SingleBorder : public Border
{
public:
	SingleBorder() {};
	void createBorder(Graphics& graphics, short left, short top, short width, short height);
};

class DoubleBorder : public Border
{
public:
	DoubleBorder() {};
	void createBorder(Graphics& graphics, short left, short top, short width, short height);
};