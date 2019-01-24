//
// Created by greco on 10/13/2018.
//

#include "CLookUpQueue.hpp"
#include "../Request.hpp"
using namespace std;

void CLookUpQueue::addRequest(Request *request) {
    CLookUpQueueNode *rNode = new CLookUpQueueNode(request);
    CLookUpQueueNode *curr = head;
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
        if (curr->next() == nullptr) {
            curr->next(rNode);
            tail = rNode;
            return;
        }
        while (rNode->request()->track() > curr->next()->request()->track() && curr->next()->request()->track() < 100 && curr->next()->request()->track() > head->request()->track()) {
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
        if (curr->next() == nullptr) {
            curr->next(rNode);
            tail = rNode;
            return;
        }
        while (curr->next()->request()->track() >= head->request()->track()){
            curr = curr->next();
            if (curr->next() == nullptr) {
                curr->next(rNode);
                tail = rNode;
                return;
            }
        }
        while (rNode->request()->track() > curr->next()->request()->track()){
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

Request *CLookUpQueue::getRequest() {
    if( isEmpty() ) {
        std::cout << "Calling SameTrackQueue::getRequest() on empty queue. Terminating...\n";
        exit(1);
    }
    CLookUpQueueNode *CLookUpQueueNode = head;
    Request *request = CLookUpQueueNode->request();
    head = head->next();
    if( head == nullptr )
        tail = nullptr;
    delete CLookUpQueueNode;
    return request;
}

bool CLookUpQueue::isEmpty() {
    return head == nullptr;
}

void CLookUpQueue::print() {
    for(auto cur = head; cur; cur = cur->next() )
        cur->request()->print();
}

CLookUpQueue::~CLookUpQueue() {
    while( head != nullptr ) {
        CLookUpQueueNode *node = head;
        head = node->next();
        delete node;
    }
}