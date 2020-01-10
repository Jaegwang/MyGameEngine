//
//  main.cpp
//  MyGameEngine
//
//  Created by Jaegwang Lim on 2019/12/26.
//  Copyright © 2019 Jaegwang Lim. All rights reserved.
//

#include <iostream>

#include "Object.h"
#include "ShortStringArray.h"
#include "ShortString.h"
#include "Queue.h"
#include "ThreadPool.h"
#include "Launcher.h"
#include "Async.h"

int main( const int argc, const char** argv )
{
    AsyncPool pool;

    pool.initialize( 30 );

/*
    std::vector<int> buffer;
    buffer.resize( 100 );

    auto kernel = [&](unsigned n){

        buffer[n] = n;

    };

    pool.launch( kernel, 100 );

    for( int i=0; i<100; ++i )
    {
        std::cout<< buffer[i] << std::endl;
    }

*/

    std::cout<<"end prop"<<std::endl;
    return 1;
}
