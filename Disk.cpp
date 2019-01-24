//
// Created by greco on 10/16/18.
//

#include "Disk.hpp"
#include <cmath>


float Disk::getAccessTime(int incomingTrack, int incomingSector, float IncomingTime) {
    setINIT(IncomingTime);
    float seekTime = getSeekTime(incomingTrack);
    float rotationalTime = getRotationalDelay(incomingSector);
    float transferTime = getTransferTime();
    float time = seekTime+rotationalTime + transferTime;
    return time;
}

void Disk::setINIT(float incomingTime){
    _InIt = incomingTime ;

}



float Disk::getRotationalDelay(int incomingSector) {
    float x = 0;
    int padding = 0;
    if(_sector > incomingSector) {
        padding = 30 - _sector;
        x = padding + incomingSector;
        x = x*.1f;
        _sector = incomingSector;
        return x;
    }
    else if  (_sector == incomingSector){
        x =3;
        return x;
    }
    else {
        x = (incomingSector - _sector);
        x = x*.1f;
        _sector = incomingSector;

        return x;
    }
}

float Disk::getSeekTime(int incomingTrack) {

   int x = abs(incomingTrack - _track);
    x = x * 3;
    _track = incomingTrack;
    return x;

}

float Disk::getTransferTime() {
    if( _isFirstAccess ) {
        _isFirstAccess = false;
        return 0.1;
    }
    return 0;
}

