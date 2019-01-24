//
// Created by greco on 10/13/2018.
//

#include "PickUpQueue.hpp"
#include "../Request.hpp"
#include <iostream>
using namespace std;

void PickUpQueue::addRequest(Request *request) {
    PickUpQueueNode *rNode = new PickUpQueueNode(request);
    PickUpQueueNode *curr = head;
    if( isEmpty() ) { // Start Linked List
        head = tail = rNode;
        return;
    }
    if(curr->next() == nullptr) { // Put number two in.
        curr->next(rNode);
        tail = rNode;
        return;
    }

    if (curr->request()->track() > rNode->request()->track()) {
        if (curr->next() == nullptr) {
            curr->next(rNode);
            tail = rNode;
            return;
        }
        while (curr->next()->request()->track() > rNode->request()->track()){
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

    if (rNode->request()->track() > curr->request()->track()) {
        if (curr->next() == nullptr) {
            curr->next(rNode);
            tail = rNode;
            return;
        }

        while (0 < curr->next()->request()->track()) {
            curr = curr->next();
            if (curr->next() == nullptr) {
                curr->next(rNode);
                tail = rNode;
                return;
            }

            if (curr->next()->request()->track() < rNode->request()->track() && curr->next()->request()->track() > head->request()->track()){
                rNode->next(curr->next());
                curr->next(rNode);
                return;
            }
        }
    }


    if (rNode->request()->track() == curr->request()->track()){
        rNode->next(curr->next());
        curr->next(rNode);
        return;
    }
}

Request *PickUpQueue::getRequest() {
    if( isEmpty() ) {
        std::cout << "Calling FCFSQueueNode::getRequest() on empty queue. Terminating...\n";
        exit(1);
    }
    PickUpQueueNode *PupNode = head;
    Request *request = PupNode->request();
    head = head->next();
    if( head == nullptr )
        tail = nullptr;
    delete PupNode;
    return request;
}

bool PickUpQueue::isEmpty() {
    return head == nullptr;
}

void PickUpQueue::print() {
    for(auto cur = head; cur; cur = cur->next() )
        cur->request()->print();
}

PickUpQueue::~PickUpQueue() {
    while( head != nullptr ) {
        PickUpQueueNode *node = head;
        head = node->next();
        delete node;
    }
}
