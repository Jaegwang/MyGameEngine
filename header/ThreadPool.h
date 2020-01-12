//
//  ThreadPool.h
//  MyGameEngine
//
//  Created by Jaegwang Lim on 2020/01/03.
//  Copyright © 2020 Jaegwang Lim. All rights reserved.
//

#pragma once
#include <vector>
#include <future>
#include <atomic>
#include <algorithm>
#include <SPMCQ.h>

class TaskFunction
{

};

class ThreadPool
{
private:
    
    std::vector<std::future<void>> futures;

    SPMCQ<TaskFunction> workQueue;

    int numTotalThreads;

    std::atomic<bool> exitSignal = false;

public:

    ThreadPool()
    {}

    void initialize( const unsigned num )
    {
        numTotalThreads = num;

        auto ff = [&](int tid){

            while( !exitSignal )
            {
                // Pop task.

            }
        };

        for( int n=0; n<numTotalThreads; ++n )
        {
            futures.push_back( std::async(std::launch::async, ff, n) );
        }
    }




    
};
