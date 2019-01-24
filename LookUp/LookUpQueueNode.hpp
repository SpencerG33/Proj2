//
// Created by greco on 10/13/2018.
//

#ifndef PROJ2_LOOKUPQUEUENODE_HPP
#define PROJ2_LOOKUPQUEUENODE_HPP


using namespace std;
class Request;

class LookUpQueueNode {
public:
    LookUpQueueNode(Request *req, LookUpQueueNode *nextPtr);
    LookUpQueueNode(Request *req);
    LookUpQueueNode *next();
    void next(LookUpQueueNode *node);
    Request *request();

private:
    LookUpQueueNode *_next;

    Request *_request;
};


#endif //PROJ2_LOOKUPQUEUENODE_HPP
