//
// Created by greco on 10/13/2018.
//

#ifndef PROJ2_SAMETRACKQUEUE_HPP
#define PROJ2_SAMETRACKQUEUE_HPP

#include<iostream>
#include "../Queue.hpp"
#include "SameTrackQueueNode.hpp"
#include "../Request.hpp"
using namespace std;

class Request;

class SameTrackQueue: public Queue {

public:
    SameTrackQueue(): head(nullptr), tail(nullptr) {}

    virtual void addRequest(Request *request);

    virtual Request *getRequest();
    virtual bool isEmpty();
    virtual void print();
    virtual ~SameTrackQueue();

private:
    SameTrackQueueNode *head, *tail;
};


#endif //PROJ2_SAMETRACKQUEUE_HPP
