
#pragma once

#include <future>
#include <iostream>
#include <atomic>
#include <algorithm>

class AsyncPool
{
private:

    std::function<void(unsigned)> kernel;

    std::vector<std::future<void>> futures;
    std::vector<bool> isReady;

    int numTotalThreads;
    int numElements;

    std::atomic<bool> exitSignal = false;
    std::atomic<int>  joinable = 0;


public:

    void initialize(int totalThreads)
    {
        numTotalThreads = totalThreads;

        auto ff = [&](int tid){

            while( !exitSignal )
            {
                while(isReady[tid] == false) if(exitSignal) return;

                const int numThreads = std::min(numTotalThreads, numElements);

                if( tid < numThreads )
                {
                    const unsigned L = numElements / (unsigned)numThreads;
                    const unsigned S = numElements % numThreads;

                    int E = tid == numThreads-1 ? L+S : L;

                    for( int n=tid*L; n<tid*L+E; ++n ) kernel( n );
                }

                isReady[tid] = false;
                joinable++;
            }
        };


        for( int n=0; n<numTotalThreads; ++n )
        {
            futures.push_back( std::async(std::launch::async, ff, n) );
            isReady.push_back( false );
        }

    }

    void launch( std::function<void(unsigned)> f, unsigned num )
    {
        numElements = num;
        kernel = f;
        joinable = 0;

        for( int n=0; n<numTotalThreads; ++n ) isReady[n] = true;

        while( joinable < numTotalThreads );
    }

    void exit()
    {
        exitSignal = true;
    }

};
