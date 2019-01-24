//
// Created by greco on 10/15/2018.
//

#include "EventQueue.hpp"
#include "Request.hpp"
#include <iostream>
using namespace std;

void EventQueue::addRequest(Request *request, int requestType) {
    EventNode *rNode = new EventNode(request);
    EventNode *curr = head;

    switch (requestType)
    {
        case 0:
            rNode->setRequestEvent(true);
            request->setRequest(true);
            break;
        case 1:
            rNode->setDDoneEvent(true);
            rNode->setFCFS(true);
            request->setFCFS(true);
            break;
        case 2:
            rNode->setDDoneEvent(true);
            rNode->setSameTrack(true);
            request->setSTrack(true);
            break;
        case 3:
            rNode->setDDoneEvent(true);
            rNode->setPickUp(true);
            request->setPickUp(true);
            break;
        case 4:
            rNode->setDDoneEvent(true);
            rNode->setLookUp(true);
            request->setLookUp(true);
            break;
        case 5:
            rNode->setDDoneEvent(true);
            rNode->setCLookUp(true);
            request->setCLookUp(true);
            break;

        case 6:
            rNode->setTimerEvent(true);
            request->setTimerEvent(true);
            break;

    }

    if( isEmpty() ) {
        head = tail = rNode;
        return;
    }

    if(head->request()->time() > rNode->request()->time()){
        rNode->next(head);
        head =rNode;
        return;
    }

    if (curr->next() == nullptr) {
        head->next(rNode);
        tail = rNode;
        return;
    }
    if(curr->next()->request()->time() > rNode->request()->time()){
        rNode->next(curr->next());
        curr->next(rNode);
        return;
    }
    if (curr->next()->request()->time() < rNode->request()->time()){
        while (curr->next()->request()->time() < rNode->request()->time()){
            curr = curr->next();
            if (curr->next() == nullptr) {
                curr->next(rNode);
                tail = rNode;
                return;
            }
        }
        rNode->next(curr->next());
        curr->next(rNode);
        return;
    }

}


Request *EventQueue::getRequest() {
    if( isEmpty() ) {
        std::cout << "Calling EventQueueNode::getRequest() on empty queue. Terminating...\n";
        exit(1);
    }
    EventNode *ENode = head;
    Request *request = ENode->request();
    head = head->next();
    if( head == nullptr )
        tail = nullptr;
    delete ENode;
    return request;
}

void EventQueue::deleteHead() {
    EventNode *ENode = head;
    head = head->next();
    if( head == nullptr )
        tail = nullptr;
    delete ENode;
}



double EventQueue::findWaitTime(Request *request, int requestType) {
    double waitTime = 0;
    EventNode *rNode = new EventNode(request);
    EventNode *curr = head;
    if (requestType == 2) {
        while (curr->isDiskDoneEvent() && curr->getFCFS()) {
            curr = curr->next();
        }
        waitTime = curr->request()->time() - rNode->request()->time();
        return waitTime;
    }


}

bool EventQueue::isEmpty() {
    return head == nullptr;
}

void EventQueue::print() {
    for(auto cur = head; cur; cur = cur->next() )
        cur->request()->print();
}




