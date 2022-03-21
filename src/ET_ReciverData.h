//
// Created by Jupiter Moll on 11.03.2022.
//

#ifndef RECIVERDATA_H
#define RECIVERDATA_H


#include "Arduino.h"

struct ET_ReciverData {

    uint8_t  leftRacketHit;
    uint8_t  rightRacketHit;
    uint8_t  leftTableHit;
    uint8_t  rightTableHit;
    uint32_t leftRacketSpeed;
    uint32_t rightRacketSpeed;
};


#endif //RECIVERDATA_H
