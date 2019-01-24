//
// Created by greco on 10/13/2018.
//

#ifndef PROJ2_CLOOKUPQUEUE_HPP
#define PROJ2_CLOOKUPQUEUE_HPP

#include<iostream>
#include "../Queue.hpp"
#include "CLookUpQueueNode.hpp"

using namespace std;

class Request;

class CLookUpQueue: public Queue {

public:
    CLookUpQueue(): head(nullptr), tail(nullptr) {}

    virtual void addRequest(Request *request);

    virtual Request *getRequest();
    virtual bool isEmpty();
    virtual void print();
    virtual ~CLookUpQueue();

private:
    CLookUpQueueNode *head, *tail;
};


#endif //PROJ2_CLOOKUPQUEUE_HPP
