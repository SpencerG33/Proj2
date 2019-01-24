//
// Created by greco on 10/1/18.
//

#ifndef QUEUE_HPP
#define QUEUE_HPP
using namespace std;
class Request;
//Super Class for all of the queues
class Queue {

public:
    virtual void addRequest(Request *request) = 0;
    virtual Request *getRequest() = 0;
    virtual bool isEmpty() = 0;
    virtual void print() = 0;
    virtual ~Queue() {}

};

#endif // QUEUE_HPP
