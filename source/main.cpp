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
#include "SPMCQ.h"

int main( const int argc, const char** argv )
{
    ThreadPool thPool;
    AsyncPool pool;

    thPool.initialize( 10 );

    std::cout<<"end prop"<<std::endl;
    return 1;
}
