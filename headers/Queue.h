//http://www.sevangelatos.com/lockless-single-producer-single-consumer-bounded-queue/
#pragma once


class Queue
{
private:
    
    std::atomic<int> front = 0;
    std::atomic<int> rear = 0;
    
    unsigned num = 10;
    
public:
    
    Queue()
    {}
    
    ~Queue()
    {}
    
    bool isEmpty()
    {
        if(front == rear) return true;
        return false;
    }
    
    bool isFull()
    {
        if(front+1 == rear) return true;
        return false;
    }
    
    int push()
    {
        if(isFull()) return -1;
        int f = front;
        front = (f+1)%num;
        return f;
    }
    
    int pop()
    {
        if(isEmpty()) return -1;
        int r = rear;
        rear = (r+1)%num;
        return r;
    }
    
};
