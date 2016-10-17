/**
 * UIMathFraction.h
 *
 * A widget to build the math fraction
 *
 * cocos2d-x-tools
 *
 * Created by Alex on 17/10/2016.
 */

#ifndef _UI_MATH_FRACTION_H_
#define _UI_MATH_FRACTION_H_

#include "cocos2d.h"
#include "ui/UILayout.h"

class MathFraction :
public cocos2d::ui::Layout
{
public:

    MathFraction();
    ~MathFraction();

    CREATE_FUNC(MathFraction);

    virtual bool init();
};

#endif // _UI_MATH_FRACTION_H_
