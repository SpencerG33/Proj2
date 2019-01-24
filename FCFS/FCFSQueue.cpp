//
// Created by greco on 10/13/2018.
//

#include "FCFSQueue.hpp"
#include "../Request.hpp"
#include <iostream>
using namespace std;

void FCFSQueue::addRequest(Request *request) {
    FCFSQueueNode *rNode = new FCFSQueueNode(request);
    if( isEmpty() ) {
        head = tail = rNode;
    } else {
        tail->next(rNode);
        tail = rNode;
    }
}

Request *FCFSQueue::getRequest() {
    if( isEmpty() ) {
        exit(1);
    }
    FCFSQueueNode *fcfsNode = head;
    Request *request = fcfsNode->request();
    head = head->next();
    if( head == nullptr )
        tail = nullptr;
    delete fcfsNode;
    return request;
}

bool FCFSQueue::isEmpty() {
    return head == nullptr;
}

void FCFSQueue::print() {
    for(auto cur = head; cur; cur = cur->next() )
        cur->request()->print();
}

FCFSQueue::~FCFSQueue() {
    while( head != nullptr ) {
        FCFSQueueNode *node = head;
        head = node->next();
        delete node;
    }
}

