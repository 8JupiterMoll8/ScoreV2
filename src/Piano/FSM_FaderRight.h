//
// Created by Jupiter Moll on 21.03.2022.
//

#ifndef UNTITLED21_FSM_FADERRIGHT_H
#define UNTITLED21_FSM_FADERRIGHT_H


#include "I_FSM_Fader.h"

class FSM_FaderRight : public I_FSM_Fader {

public:
    FSM_FaderRight(ET_ReciverData &event, FaderSimple &fader) : I_FSM_Fader(event, fader) {}



    void setup() override {
        _fader.setup();
        _fader.setStartValue(5.0);
        _fader.setEndValue(60.0);
    }

    void loop() override {

        _fader.loop();
        stateMachine();
        l_CH[4]= _fader.getValue();
        int note = map(_fader.getValue(),
                       _fader.getStartValue(),
                       _fader.getEndValue(),
                       60.0,
                       5.0
                       );

        usbMIDI.sendNoteOn(_fader.getValue(),72,9);

    }

private:
    void st_Idle() override {
        if (_event.rightRacketHit == 1) {
            _state = FADE_IN_START;
            _fader.setSpeed(5);
            _fader.reverse();
            Serial.println("FADE_IN_START");
            usbMIDI.sendNoteOn(58,72,10);
        }

    }

    void st_FadeInStart() override {
        //Do:
        _fader.start();
        Serial.println(_fader.getValue());


        //Leave:
        //if fader reach the end of fading
        if (_fader.isComplete()) {
            _fader.reverse();
            _state = FADE_IN_STOP;
            Serial.println("FADE_IN_STOP");
        }
        //Leave:
        //if ball hit table before fading end is complete
        if (_event.rightRacketHit == 1) {
            _state = FADE_OUT_START;
            _fader.reverse();
            Serial.println("FADE_OUT_START");

        }
    }

    void st_FadeInStop() override {
        //Do:
       // Serial.println( _fader.getValue());
        _fader.stop(); // Flag false

        //Leave:
        if (_event.rightRacketHit == 1) {
            _state = FADE_OUT_START;
            _fader.setValue(6);
            Serial.println("FADE_OUT_START");
        }
    }

    void st_FadeOutStart() override {
        //Do:
        _fader.start();
        usbMIDI.sendNoteOff(58,72,10);
        Serial.println( _fader.getValue());

        //Leave:
        //if fader reach the end of fading
        if (_fader.isComplete()) {
            _fader.reverse();
            _state = FADE_OUT_STOP;
            Serial.println("FADE_OUT_STOP");
        }
        if (_event.rightRacketHit == 1) {
            _fader.reverse();
            _state = FADE_IN_START;
            Serial.println("FADE_IN_START");
        }

    }
    void st_FadeOutStop() override {
        _fader.stop();
        if (_event.rightRacketHit == 1) {
            _fader.setValue(59);
            _state = FADE_IN_START;
        }
    }
};


#endif //UNTITLED21_FSM_FADERRIGHT_H
