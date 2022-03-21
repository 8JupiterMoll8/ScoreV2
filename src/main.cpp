#include <Arduino.h>
#include "ET_ReciverData.h"
#include <EasyTransfer.h>
#include "Birnen.hpp"
#include "KnightRider.h"
#include "FadeAll.h"
#include "FaderSimple.h"
#include "I_FSM_Fader.h"
#include "FSM_FaderRight.h"


/*
███████╗ █████╗ ███████╗██╗   ██╗  ████████╗██████╗  █████╗ ███╗   ██╗███████╗███████╗███████╗██████╗
██╔════╝██╔══██╗██╔════╝╚██╗ ██╔╝  ╚══██╔══╝██╔══██╗██╔══██╗████╗  ██║██╔════╝██╔════╝██╔════╝██╔══██╗
█████╗  ███████║███████╗ ╚████╔╝      ██║   ██████╔╝███████║██╔██╗ ██║███████╗█████╗  █████╗  ██████╔╝
██╔══╝  ██╔══██║╚════██║  ╚██╔╝       ██║   ██╔══██╗██╔══██║██║╚██╗██║╚════██║██╔══╝  ██╔══╝  ██╔══██╗
███████╗██║  ██║███████║   ██║███████╗██║   ██║  ██║██║  ██║██║ ╚████║███████║██║     ███████╗██║  ██║
╚══════╝╚═╝  ╚═╝╚══════╝   ╚═╝╚══════╝╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚══════╝╚═╝     ╚══════╝╚═╝  ╚═╝
 */

EasyTransfer ET;
ET_ReciverData event;


/*
██╗     ██╗ ██████╗ ██╗  ██╗████████╗
██║     ██║██╔════╝ ██║  ██║╚══██╔══╝
██║     ██║██║  ███╗███████║   ██║
██║     ██║██║   ██║██╔══██║   ██║
███████╗██║╚██████╔╝██║  ██║   ██║
╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝
 */

//KnightRider l_knightRider(l_CH);
//KnightRider r_knightRider(r_CH);
//FadeAll fadeAll(l_CH, r_CH);

//FaderSimple faderSimple;
//FaderAuto faderAuto;

//FaderArduino faderArduino(event, ET);
FaderSimple faderSimple;
FSM_FaderRight fsmFaderRight(event,faderSimple);



void setup() {
    Serial.begin(115200);
    while (!Serial) {}
    Serial.println("Alfis Dimmer");

    //Init EasyTransfer
    Serial1.begin(115200);
    ET.begin(details(event), &Serial1);

    //Init Dimmer
    setup_Dimmer();

    //Init FsmFader
    fsmFaderRight.setup();
}

void loop() {
    if (ET.receiveData()) {
        fsmFaderRight.loop();
    }


};