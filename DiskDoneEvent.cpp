//
// Created by greco on 10/13/2018.
//
#include <fstream>
#include <iomanip>
#include "DiskDoneEvent.hpp"

DiskDoneEvent::DiskDoneEvent(double rTime, int rTrack, int rSector) : _time(rTime), _track(rTrack), _sector(rSector), _Entr(0), _Init(0), _Comp(0), _Wait(0), _Serv(0), _TimInSys(0) {}

int DiskDoneEvent::track() { return _track; }

int DiskDoneEvent::sector() { return _sector; }

double DiskDoneEvent::time() { return _time; }

void DiskDoneEvent::setTime(float time) {_time = time; }

void DiskDoneEvent::saveTime() {_oTime = _time; }

void DiskDoneEvent::calculations(float Comp) {
    _Entr = _oTime;
    _Serv = _time;
    _Init = Comp;
    if (_Init == 0)
        _Init = _Entr;
    _Comp = _Init + _Serv;
    _Wait = _Init - _Entr;
    _TimInSys = _Wait + _Serv;

}

double DiskDoneEvent::getComp() { return _Comp; }

double DiskDoneEvent::getIniT() { return _Init;}

double DiskDoneEvent::getTimeInSys () { return _TimInSys;}

double DiskDoneEvent::getWaitTime() { return _Wait; }

double DiskDoneEvent::getServ () { return  _Serv; }




void DiskDoneEvent::print(int file) {

    if (file == 1){
        fstream FCFSFile;
        FCFSFile.open("FCFS_TextFile.txt", ios::app);
        FCFSFile << _track << setw(10) << _sector << setw(10) << _Entr << setw(10)<< _Init << setw(10)<< _Comp <<setw(10)<< _Wait << setw(10)<< _Serv << setw(10)<< _TimInSys <<endl;
        FCFSFile.close();
    }

    if (file == 2){
        fstream STRACKFile;
        STRACKFile.open("STRACK_TextFile.txt", fstream::app);
        STRACKFile << _track << setw(10) << _sector << setw(10) << _Entr << setw(10)<< _Init << setw(10)<< _Comp <<setw(10)<< _Wait << setw(10)<< _Serv << setw(10)<< _TimInSys <<endl;
        STRACKFile.close();
    }

    if (file == 3){
        fstream PICKUPFile;
        PICKUPFile.open("PICKUP_TextFile.txt", ios::app);
        PICKUPFile << _track << setw(10) << _sector << setw(10) << _Entr << setw(10)<< _Init << setw(10)<< _Comp <<setw(10)<< _Wait << setw(10)<< _Serv << setw(10)<< _TimInSys <<endl;
        PICKUPFile.close();
    }

    if (file == 4){
        fstream LOOKFile;
        LOOKFile.open("LOOK_TextFile.txt", fstream::app);
        LOOKFile << _track << setw(10) << _sector << setw(10) << _Entr << setw(10)<< _Init << setw(10)<< _Comp <<setw(10)<< _Wait << setw(10)<< _Serv << setw(10)<< _TimInSys <<endl;
        LOOKFile.close();
    }

    if (file == 5){
        fstream CLOOKFile;
        CLOOKFile.open("CLOOK_TextFile.txt", fstream::app);
        CLOOKFile << _track << setw(10) << _sector << setw(10) << _Entr << setw(10)<< _Init << setw(10)<< _Comp <<setw(10)<< _Wait << setw(10)<< _Serv << setw(10)<< _TimInSys <<endl;
        CLOOKFile.close();
    }
}