//
// Created by greco on 10/13/2018.
//

#ifndef PROJ2_DISKDONEEVENT_HPP
#define PROJ2_DISKDONEEVENT_HPP

#include <string>
using namespace std;

class DiskDoneEvent {

public:
    DiskDoneEvent(double rTime, int rTrack, int rSector);
    int track();
    int sector();
    double time();
    void print(int);
    void setTime(float);
    void calculations(float);
    void saveTime();
    double getComp();
    double getIniT();
    double getTimeInSys();
    double getWaitTime();
    double getServ();


private:
    double _time, _Entr, _Init, _Comp, _Wait, _Serv, _TimInSys, _oTime;
    int _track, _sector;





};


#endif //PROJ2_DISKDONEEVENT_HPP
