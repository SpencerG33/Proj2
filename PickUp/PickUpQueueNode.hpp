//
// Created by greco on 10/13/2018.
//
#include <iostream>
#ifndef PROJ2_PICKUPQUEUENODE_HPP
#define PROJ2_PICKUPQUEUENODE_HPP
using namespace std;

class Request;

class PickUpQueueNode {
public:
    PickUpQueueNode(Request *req, PickUpQueueNode *nextPtr);
    PickUpQueueNode(Request *req);
    PickUpQueueNode *next();
    void next(PickUpQueueNode *node);
    Request *request();

private:
    PickUpQueueNode *_next;
    Request *_request;
};


#endif //PROJ2_PICKUPQUEUENODE_HPP
