#pragma once
#include <atomic>

template< class T >
class SPMCQ
{
private:

    std::atomic<int> front = 0;
    std::atomic<int> rear = 0;

    unsigned num;
    T* arr = 0;

public:

    void initialize( const int N )
    {
        arr = new T[N];
        num = N;

        front = rear = 0;
    }

    int push(const T& v)
    {
        int next_front = (front+1)%num;
        if( next_front == rear ) return -1; // is Full.

        int r = front;
        arr[r] = v;

        //int f = front;
        //front = next_front;

        //return f;

        return 0;
    }

    int pop( T& v )
    {
        int r(-1);
        int b;

        do
        {
            r = rear;
            if( r == front ) return -1; // is Empty().

            b = (r+1)%num;

        } while ( !std::atomic_compare_exchange_weak(&rear, &r, b) );

        v = arr[r];

        return r;
    }

};

