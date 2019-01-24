//
// Created by greco on 10/13/2018.
//

#include "LookUpQueueNode.hpp"
class Request;

LookUpQueueNode::LookUpQueueNode(Request *req, LookUpQueueNode *nextPtr) : _request(req), _next(nextPtr) {}

LookUpQueueNode::LookUpQueueNode(Request *req) : _request(req), _next(nullptr) {}

LookUpQueueNode *LookUpQueueNode::next() {
    return _next;
}


void LookUpQueueNode::next(LookUpQueueNode *node) {
    _next = node;
}


Request *LookUpQueueNode::request() {
    return _request;
}
