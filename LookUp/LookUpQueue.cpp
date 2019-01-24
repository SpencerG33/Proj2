//
// Created by greco on 10/13/2018.
//
#include "LookUpQueue.hpp"
#include "../Request.hpp"
using namespace std;

void LookUpQueue::addRequest(Request *request) {
    LookUpQueueNode *rNode = new LookUpQueueNode(request);
    LookUpQueueNode *curr = head;
    if (isEmpty()) {
        head = tail = rNode;
        return;
    }
    if (curr->next() == nullptr) {
        head->next(rNode);
        tail = rNode;
        return;
    }

    if (rNode->request()->track() > curr->request()->track()) {

        while (rNode->request()->track() > curr->next()->request()->track() &&
               curr->next()->request()->track() <= 100 && curr->next()->request()->track() > head->request()->track()) {
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

    if (rNode->request()->track() < curr->request()->track()){
        while (rNode->request()->track() < curr->next()->request()->track()){
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

}

Request *LookUpQueue::getRequest() {
    if( isEmpty() ) {
        std::cout << "Calling SameTrackQueue::getRequest() on empty queue. Terminating...\n";
        exit(1);
    }
    LookUpQueueNode *LookUpQueueNode = head;
    Request *request = LookUpQueueNode->request();
    head = head->next();
    if( head == nullptr )
        tail = nullptr;
    delete LookUpQueueNode;
    return request;
}

bool LookUpQueue::isEmpty() {
    return head == nullptr;
}

void LookUpQueue::print() {
    for(auto cur = head; cur; cur = cur->next() )
        cur->request()->print();
}

LookUpQueue::~LookUpQueue() {
    while( head != nullptr ) {
        LookUpQueueNode *node = head;
        head = node->next();
        delete node;
    }
}