//
// Created by student on 10/16/18.
//

#ifndef PROJ2_DISK_HPP
#define PROJ2_DISK_HPP


class Disk {
public:
    Disk(): _track(0), _sector(0), _currTime(0), _ready(true), _isFirstAccess(true) {}


    float getSeekTime(int track);
    float getRotationalDelay(int sector);
    float getTransferTime();
    float getAccessTime(int track, int sector, float time);
    void setINIT(float);



private:
    int _track;
    int _sector;
    float _currTime;
    bool _ready;
    float _InIt;
    bool _isFirstAccess;



};


#endif //PROJ2_DISK_HPP
