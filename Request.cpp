//
// Created by greco on 10/1/18.
//

#include <iostream>
#include "Request.hpp"
#include <fstream>

using namespace std;

Request::Request(double rTime, int rTrack, int rSector) : _time(rTime), _track(rTrack), _sector(rSector), _Entr(0), _Init(0), _Comp(0), _Wait(0), _Serv(0), _TimInSys(0), _isRequest(false), _isDDEvent(false) ,_timerEvent(
        false), _isFCFS(false), _STrack(false), _PickUp(false), _LookUp(false), _CLookUp(false){}

Request::Request(double rTime) : _time(rTime), _track(0), _sector(0), _Entr(0), _Init(0), _Comp(0), _Wait(0), _Serv(0), _TimInSys(0), _isRequest(false), _isDDEvent(false),_timerEvent(
        false), _isFCFS(false), _STrack(false), _PickUp(false), _LookUp(false), _CLookUp(false) {}

Request::Request() : _time(0), _track(0), _sector(0), _Entr(0), _Init(0), _Comp(0), _Wait(0), _Serv(0), _TimInSys(0), _isRequest(false), _isDDEvent(false),_timerEvent(
        false), _isFCFS(false), _STrack(false), _PickUp(false), _LookUp(false), _CLookUp(false) {}

int Request::track() { return _track; }

int Request::sector() { return _sector; }

double Request::time() { return _time; }

void Request::setDDevent(bool anwser) {_isDDEvent = anwser; }
bool Request::isDDevent() { return _isDDEvent; }

void Request::setRequest(bool anwser) { _isRequest = anwser; }
bool Request::isRequest() { return _isRequest; }
void Request::setTimerEvent(bool anwser) {_timerEvent = anwser;}
bool Request::issTimerEvent()  { return _timerEvent;}
void Request::setFCFS(bool anwser) {_isFCFS = anwser;}
bool Request::isFCFS() { return _isFCFS; }
void Request::setSTrack(bool anwser) {_STrack = anwser; }
bool Request::isStrack() { return  _STrack; }
void Request::setPickUp(bool anwser) {_PickUp = anwser;}
bool Request::isPickUp() { return _PickUp;}
void Request::setLookUp(bool anwser) {_LookUp = anwser;}
bool Request::isLookUp() { return _LookUp; }
void Request::setCLookUp(bool anwser) {_CLookUp = anwser;}
bool Request::isCLookUp() { return _CLookUp;}


void Request::print() {
    fstream FCFSFile;
    FCFSFile.open("FCFS_TextFile.txt", fstream::app);
    FCFSFile << _track << "    " << _sector << "    " << _Entr << "    "<< _Init << "    "<< _Comp <<"    "<< _Wait << "    "<< _Serv << "    "<< _TimInSys <<endl;
    FCFSFile.close();
}
