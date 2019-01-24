//
// Created by greco on 10/13/2018.
//

#include "SameTrackQueue.hpp"
#include "../Request.hpp"
using namespace std;

void SameTrackQueue::addRequest(Request *request) {
    SameTrackQueueNode *rNode = new SameTrackQueueNode (request);
    SameTrackQueueNode *curr = head;
    if( isEmpty() ) {
        head = tail = rNode;
        return;
    }
    if(curr->next() == nullptr) {
        head->next(rNode);
        tail = rNode;
        return;
    }
    while (curr->next() != nullptr) {
        if (curr->request()->track() == rNode->request()->track()) {
            while (curr->next()->request()->track() == rNode->request()->track()) {
                curr = curr->next();
            }
            rNode->next(curr->next());
            curr->next(rNode);
            return;
        }
        curr = curr->next();
    }
    tail->next(rNode);
    tail = rNode;



}

Request *SameTrackQueue::getRequest() {
    if( isEmpty() ) {
        std::cout << "Calling SameTrackQueue::getRequest() on empty queue. Terminating...\n";
        exit(1);
    }
    SameTrackQueueNode *SameTrackQueueNode = head;
    Request *request = SameTrackQueueNode->request();
    head = head->next();
    if( head == nullptr )
        tail = nullptr;
    delete SameTrackQueueNode;
    return request;
}

bool SameTrackQueue::isEmpty() {
    return head == nullptr;
}

void SameTrackQueue::print() {
    for(auto cur = head; cur; cur = cur->next() )
        cur->request()->print();
}

SameTrackQueue::~SameTrackQueue() {
    while( head != nullptr ) {
        SameTrackQueueNode *node = head;
        head = node->next();
        delete node;
    }
}