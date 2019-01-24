//
// Created by greco on 10/13/2018.
//

#ifndef PROJ2_LOOKUPQUEUE_HPP
#define PROJ2_LOOKUPQUEUE_HPP


#include<iostream>
#include "../Queue.hpp"
#include "LookUpQueueNode.hpp"

using namespace std;

class Request;

class LookUpQueue: public Queue {

public:
    LookUpQueue(): head(nullptr), tail(nullptr) {}

    virtual void addRequest(Request *request);

    virtual Request *getRequest();
    virtual bool isEmpty();
    virtual void print();
    virtual ~LookUpQueue();

private:
    LookUpQueueNode *head, *tail;
};

#endif //PROJ2_LOOKUPQUEUE_HPP
