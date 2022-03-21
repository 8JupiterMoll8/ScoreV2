//
// Created by Jupiter Moll on 21.03.2022.
//

#ifndef UNTITLED21_I_FSM_FADER_H
#define UNTITLED21_I_FSM_FADER_H


#include "ET_ReciverData.h"
#include "FaderSimple.h"

class I_FSM_Fader {


public:
    I_FSM_Fader(ET_ReciverData &event, FaderSimple &fader) : _event(event), _fader(fader) {}

protected:
    ET_ReciverData &_event;
    FaderSimple &_fader;

    enum States {
        IDLE,
        FADE_IN_START,
        FADE_IN_STOP,
        FADE_OUT_START,
        FADE_OUT_STOP
    } _state;

    virtual void setup()           = 0;

    virtual void loop()            = 0;

    virtual void st_Idle()         = 0;

    virtual void st_FadeInStart()  = 0;

    virtual void st_FadeInStop()   = 0;

    virtual void st_FadeOutStart() = 0;

    virtual void st_FadeOutStop()   = 0;

public:

    void stateMachine() {

        switch (_state) {
            case IDLE:
                st_Idle();
                break;
            case FADE_IN_START:
                st_FadeInStart();
                break;
            case FADE_IN_STOP:
                st_FadeInStop();
                break;
            case FADE_OUT_START:
                st_FadeOutStart();
                break;
            case FADE_OUT_STOP:
                st_FadeOutStop();
                break;
        }
    }
};


#endif //UNTITLED21_I_FSM_FADER_H
