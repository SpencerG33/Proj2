//
// Created by greco on 10/13/2018.
//

#include "FCFSQueueNode.hpp"

class Request;

FCFSQueueNode::FCFSQueueNode(Request *req, FCFSQueueNode *nextPtr) : _request(req), _next(nextPtr) {}

FCFSQueueNode::FCFSQueueNode(Request *req) : _request(req), _next(nullptr) {}

FCFSQueueNode *FCFSQueueNode::next() {
    return _next;
}

void FCFSQueueNode::next(FCFSQueueNode *node) {
    _next = node;
}

Request *FCFSQueueNode::request() {
    return _request;
}
