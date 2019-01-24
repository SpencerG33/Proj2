//
// Created by greco on 10/13/2018.
//
#ifndef PROJ2_SAMETRACKNODE_HPP
#define PROJ2_SAMETRACKNODE_HPP
using namespace std;
class Request;

class SameTrackQueueNode {
public:
    SameTrackQueueNode(Request *req, SameTrackQueueNode *nextPtr);
    SameTrackQueueNode(Request *req);
    SameTrackQueueNode *next();
    void next(SameTrackQueueNode *node);
    Request *request();

private:
    SameTrackQueueNode *_next;
    Request *_request;
};


#endif //PROJ2_SAMETRACKNODE_HPP
