//
// Created by Jupiter Moll on 18.03.2022.
//

#ifndef UNTITLED21_I_FADER_H
#define UNTITLED21_I_FADER_H

#include <wiring.h>
#include "Arduino.h"



class I_Fader {

protected:
    float _speed;
    float _value;
    float _minValue;
    float _maxValue;
    float _fadeAmount = 1.0;
    boolean _toggle = false;
    elapsedMillis _ms;
public:
    float getSpeed() const {
        return _speed;
    }

    void setSpeed(float speed) {
        _speed = speed;
    }

    float getValue() const {
        return _value;
    }

    void setValue(float value) {
        _value = value;
    }

    float getStartValue() const {
        return _minValue;
    }

    void setStartValue(float startValue) {
        _minValue = startValue;
    }

    float getEndValue() const {
        return _maxValue;
    }

    void setEndValue(float endValue) {
        _maxValue = endValue;
    }



public:
    I_Fader() {}

    virtual void setup() = 0;
    virtual void loop()  = 0;
    virtual void start() = 0;
    virtual void stop()  = 0;
    virtual void reverse() = 0;
    virtual boolean isComplete() = 0;


};


#endif //UNTITLED21_I_FADER_H
