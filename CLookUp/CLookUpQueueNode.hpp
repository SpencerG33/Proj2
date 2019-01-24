//
// Created by greco on 10/13/2018.
//

#ifndef PROJ2_CLOOKUPQUEUENODE_HPP
#define PROJ2_CLOOKUPQUEUENODE_HPP


using namespace std;
class Request;

class CLookUpQueueNode {
public:
    CLookUpQueueNode(Request *req, CLookUpQueueNode *nextPtr);
    CLookUpQueueNode(Request *req);
    CLookUpQueueNode *next();
    void next(CLookUpQueueNode *node);
    Request *request();

private:
    CLookUpQueueNode *_next;

    Request *_request;
};


#endif //PROJ2_CLOOKUPQUEUENODE_HPP
