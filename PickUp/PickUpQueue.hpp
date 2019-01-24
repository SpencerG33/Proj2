//
// Created by greco on 10/13/2018.
//

#ifndef PROJ2_PICKUPQUEUE_HPP
#define PROJ2_PICKUPQUEUE_HPP

#include<iostream>
#include "../Queue.hpp"
#include "PickUpQueueNode.hpp"
#include "../Request.hpp"
using namespace std;

class Request;

class PickUpQueue: public Queue {

public:
    PickUpQueue(): head(nullptr), tail(nullptr) {}

    virtual void addRequest(Request *request);

    virtual Request *getRequest();
    virtual bool isEmpty();
    virtual void print();
    virtual ~PickUpQueue();

private:
    PickUpQueueNode *head, *tail;
};


#endif //PROJ2_PICKUPQUEUE_HPP
