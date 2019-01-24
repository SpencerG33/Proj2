//
// Created by greco on 10/15/2018.
//

#ifndef PROJ2_EVENTQUEUE_HPP
#define PROJ2_EVENTQUEUE_HPP

#include <iostream>
#include "EventNode.hpp"

class Request;

class EventQueue{

public:
    EventQueue(): head(nullptr), tail(nullptr) {}

    void addRequest(Request *request, int);

    Request *getRequest();
    void deleteHead();
    bool isEmpty();
    void print();
    EventNode getHead();
    double findWaitTime(Request *request, int);


private:
    EventNode *head, *tail;
};


#endif //PROJ2_EVENTQUEUE_HPP
