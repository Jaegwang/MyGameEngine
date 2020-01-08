#pragma once
#include <vector>
#include <future>
#include <atomic>
#include <algorithm>

class Object
{
public:
    
    virtual void Update()
    {
        
    }
    
};

class System
{
private:
    
    std::vector<std::future<void>> futures;
    std::vector< Object* > objects;
    
    std::atomic<int>  ptr = 0;
    std::atomic<bool> exitSignal = false;
    
    int step;
    int numThreads;
    int numElements;
    
public:
    
    System()
    {
        step = 4;
        numThreads = 4;
        numElements = 100;
        ptr = numElements;
    }
    
    
    virtual void run( const int idx, Object* object )
    {
        
    }
    
    void initialize()
    {
        exitSignal = false;
        
        auto kernel = [&]()
        {
            while( !exitSignal )
            {
                int pos = ptr += step;
                while( pos >= numElements );
                
                int end = std::min(pos+step, numElements);
                
                for( int x=pos; x<end; ++x)
                {
                    run( x, objects[x] );
                }
            
            }
        };
        
        futures.clear();
        
        for( int t=0; t<numThreads; ++t )
        {
            futures.push_back( std::async(std::launch::async, kernel) );
        }
        
    }
    
    void start()
    {
        ptr = -step;
    }
    void wait()
    {
        while( ptr < numElements );
    }
    
    void exit()
    {
        exitSignal = true;
    }
    
    void join()
    {
        for( int t=0; t<numThreads; ++t ) futures[t].wait();
    }
    
    
};
