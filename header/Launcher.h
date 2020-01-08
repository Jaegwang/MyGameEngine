
#pragma once
#include <vector>
#include <future>
#include <algorithm>

template<class KERNEL>
void Launch( KERNEL& kernel, const unsigned P, const unsigned N )
{
    const int numElements = N-P;
    const int numThreads = std::min(8,numElements);

    const unsigned L = numElements / numThreads;
    const unsigned S = numElements % numThreads;

    std::vector<std::future<void>> futures;

    for(unsigned t=0; t<numThreads; ++t)
    {
        futures.push_back( std::async( std::launch::async, [&](){

            int E = t == numThreads-1 ? L+S : L;
            for( int n=t*L; n<t*L+E; ++n )
                kernel( n+P );

        }));
    }

    for(unsigned t=0; t<numThreads; ++t)
    {
        futures[t].wait();
    }
}
