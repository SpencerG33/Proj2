//
// Created by greco on 10/13/2018.
//

#include "SameTrackQueueNode.hpp"
using namespace std;
class Request;

SameTrackQueueNode::SameTrackQueueNode(Request *req, SameTrackQueueNode *nextPtr) : _request(req), _next(nextPtr) {}

SameTrackQueueNode::SameTrackQueueNode(Request *req) : _request(req), _next(nullptr) {}

SameTrackQueueNode *SameTrackQueueNode::next() {
    return _next;
}

void SameTrackQueueNode::next(SameTrackQueueNode *node) {
    _next = node;
}

Request *SameTrackQueueNode::request() {
    return _request;
}