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
    
    int numElements;
    
    
public:
    
    System()
    {
        numElements = 100;
        ptr = numElements;
    }
    
    
    virtual void run( const int idx, Object* object )
    {
        
    }
    
    void start()
    {
        auto kernel = [&]()
        {
            while( !exitSignal )
            {
                while( ptr >= numElements );
                
                int pos = ptr += 4;
                int end = std::min(pos, numElements);
                
                
                for( int x=pos-4; x<end; ++x)
                {
                    run( x, objects[x] );
                }
            
            }
        };
        
        futures.clear();
        
        for( int t=0; t<4; ++t )
        {
            futures.push_back( std::async(std::launch::async, kernel) );
        }
        
    }
    
    
};
