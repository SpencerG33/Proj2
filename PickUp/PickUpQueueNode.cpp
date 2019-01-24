//
// Created by greco on 10/13/2018.
//
#include <iostream>
#include "PickUpQueueNode.hpp"
using namespace std;
class Request;

PickUpQueueNode::PickUpQueueNode(Request *req, PickUpQueueNode *nextPtr) : _request(req), _next(nextPtr) {}

PickUpQueueNode::PickUpQueueNode(Request *req) : _request(req), _next(nullptr) {}

PickUpQueueNode *PickUpQueueNode::next() {
    return _next;
}

void PickUpQueueNode::next(PickUpQueueNode *node) {
    _next = node;
}

Request *PickUpQueueNode::request() {
    return _request;
}
