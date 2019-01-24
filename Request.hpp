//
// Created by greco on 10/15/18.
//

#ifndef PROJ2_REQUEST_HPP
#define PROJ2_REQUEST_HPP
using namespace std;
class Request {
public:
    Request(double rTime, int rTrack, int rSector);
    Request(double rTIme);
    Request();

    int track();
    int sector();
    double time();
    void print();
    void setDDevent(bool);
    bool isDDevent();
    void setRequest(bool);
    bool isRequest();
    void setTimerEvent(bool);
    bool issTimerEvent();
    void setFCFS(bool);
    bool isFCFS();
    void setSTrack(bool);
    bool isStrack();
    void setPickUp(bool);
    bool isPickUp();
    void setLookUp(bool);
    bool isLookUp();
    void setCLookUp(bool);
    bool isCLookUp();

private:
    double _time, _Entr, _Init, _Comp, _Wait, _Serv, _TimInSys, _oTime;
    int _track, _sector;
    bool _isRequest, _isDDEvent, _timerEvent;
    bool _isFCFS, _STrack, _PickUp, _LookUp, _CLookUp;


};

#endif //PROJ2_REQUEST_HPP
