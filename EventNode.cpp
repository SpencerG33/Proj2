//
// Created by greco on 10/15/2018.
//
#include "EventNode.hpp"

EventNode::EventNode():timerEvent(nullptr), requestEvent(nullptr), ddoneEvent(nullptr),
                       isTimer(false), isRequest(false), isDDone(false), _next(nullptr),
                       isFCFS(false), isLookUp(false), isClookUP(false), isPickUp(false), isSameTrack(false){}

EventNode::EventNode(Request *req) : _request(req),timerEvent(nullptr), requestEvent(nullptr), ddoneEvent(nullptr),
                                     isTimer(false), isRequest(false), isDDone(false), _next(nullptr),
                                     isFCFS(false), isLookUp(false), isClookUP(false), isPickUp(false), isSameTrack(false){}




void EventNode::addRequest(Request *request) {
    _request = request;
}


EventNode *EventNode::next() { return _next; }
void EventNode::next(EventNode *node) { _next = node; }
Request *EventNode::request() { return _request; }

void  EventNode::setFCFS(bool incoming) { isFCFS = incoming;}
void  EventNode::setLookUp(bool incoming) {isLookUp = incoming;}
void  EventNode::setCLookUp(bool incoming) {isClookUP = incoming;}
void  EventNode::setPickUp(bool incoming) {isPickUp = incoming;}
void  EventNode::setSameTrack(bool incoming) {isSameTrack = incoming;}
void  EventNode::setTimerEvent(bool incoming) {isTimer =incoming; }

bool EventNode::getFCFS() { return isFCFS; }

void EventNode::setRequestEvent(bool incoming) {isRequest = incoming; }
void EventNode::setDDoneEvent(bool incoming) {isDDone = incoming; }
bool EventNode::isDiskDoneEvent() { return isDDone; }