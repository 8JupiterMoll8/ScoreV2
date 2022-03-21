//

// Created by Jupiter Moll on 18.03.2022.
//

#ifndef UNTITLED21_FADERSIMPLE_H
#define UNTITLED21_FADERSIMPLE_H


#include <wiring.h>
#include "I_Fader.h"

class FaderSimple : public I_Fader {


public:


    void setup() override {
        _minValue = 5.0;  // Light ON
        _maxValue = 60.0; // Light Off
        _value    = 59.0;
        _speed    = 1;

    }

    void loop() override {

        if (_ms > _speed) {
            _ms = 0;
            if (_toggle == true)
                _value = _value + _fadeAmount;
        }
    }

    void start() override {
        _toggle = true;

    }

    void stop()override {
        _toggle = false;
    }

    void reverse() override {
        _fadeAmount = -_fadeAmount;
    }

    boolean isComplete() override {
        if (_value <= _minValue || _value >= _maxValue)
            return true;
        else
            return false;
    }
};


#endif //UNTITLED21_FADERSIMPLE_H
