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

class ThreadPool
{
private:
    
    std::vector<std::future<void>> futures;
    
    std::atomic<int>  ptr = 0;
    std::atomic<bool> exitSignal = false;
    
    int step;
    int numThreads;
    int numElements;
    
public:
    
    ThreadPool()
    {}
    
    void initialize( int numThreads )
    {
        
        auto kernel = [&](){
            
            
        };
        
        futures.clear();
        futures.push_back( std::async( std::launch::async, kernel ) );
        
    }
    
    
};
