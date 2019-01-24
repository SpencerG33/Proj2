//
// Created by greco on 10/13/2018.
//

#include "CLookUpQueueNode.hpp"

class Request;

CLookUpQueueNode::CLookUpQueueNode(Request *req, CLookUpQueueNode *nextPtr) : _request(req), _next(nextPtr) {}

CLookUpQueueNode::CLookUpQueueNode(Request *req) : _request(req), _next(nullptr) {}

CLookUpQueueNode *CLookUpQueueNode::next() {
    return _next;
}


void CLookUpQueueNode::next(CLookUpQueueNode *node) {
    _next = node;
}


Request *CLookUpQueueNode::request() {
    return _request;
}
