#include "UIMathFraction.h"

USING_NS_CC;

MathFraction::MathFraction()
{}

MathFraction::~MathFraction()
{}

bool MathFraction::init()
{
	if (!Layout::init()) {
		return false;
	}

	return true;
}
