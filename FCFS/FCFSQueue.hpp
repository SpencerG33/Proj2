//
// Created by greco on 10/13/2018.
//
#ifndef PROJ2_FCFSQUEUE_HPP
#define PROJ2_FCFSQUEUE_HPP

#include<iostream>
#include "../Queue.hpp"
#include "FCFSQueueNode.hpp"

using namespace std;

class Request;

class FCFSQueue: public Queue {

public:
    FCFSQueue(): head(nullptr), tail(nullptr) {}

    virtual void addRequest(Request *request);

    virtual Request *getRequest();
    virtual bool isEmpty();
    virtual void print();
    virtual ~FCFSQueue();

private:
    FCFSQueueNode *head, *tail;
};


#endif //PROJ2_FCFSQUEUE_HPP
