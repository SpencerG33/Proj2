//
// Created by greco on 10/13/2018.
//

#ifndef PROJ2_FCFSQUEUENODE_HPP
#define PROJ2_FCFSQUEUENODE_HPP

using namespace std;
class Request;

class FCFSQueueNode {
public:
    FCFSQueueNode(Request *req, FCFSQueueNode *nextPtr);
    FCFSQueueNode(Request *req);
    FCFSQueueNode *next();
    void next(FCFSQueueNode *node);
    Request *request();

private:
    FCFSQueueNode *_next;
    Request *_request;
};


#endif //PROJ2_FCFSQUEUENODE_HPP
