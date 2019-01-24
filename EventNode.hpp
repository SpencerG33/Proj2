//
// Created by greco on 10/13/2018.
//

#ifndef PROJ2_EVENTNODE_HPP
#define PROJ2_EVENTNODE_HPP

#include "string"
using namespace std;

class TimerEvent;
class RequestEvent;
class DiskDoneEvent;
class Request;


class EventNode {
public:
    EventNode();
    EventNode(Request *req);
    void addRequest(Request *request);
    EventNode *next();
    void next(EventNode *node);
    Request *request();

    RequestEvent *getRequest() { return requestEvent; }
    void setRequestEvent(bool);
    bool isDiskDoneEvent();
    void setDDoneEvent(bool);

    void setFCFS(bool);
    void setLookUp(bool);
    void setCLookUp(bool);
    void setPickUp(bool);
    void setSameTrack(bool);
    void setTimerEvent(bool);

    bool getFCFS();



private:
    TimerEvent *timerEvent;
    RequestEvent *requestEvent;
    DiskDoneEvent *ddoneEvent;
    bool isTimer, isRequest, isDDone;
    bool isFCFS, isLookUp, isClookUP, isPickUp, isSameTrack;
    EventNode *_next;
    Request *_request;
};




#endif //PROJ2_EVENTNODE_HPP
