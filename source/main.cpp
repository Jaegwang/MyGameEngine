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

int main( const int argc, const char** argv )
{
    std::vector<int> bigbuffer;
    bigbuffer.resize(10000);
    
    for( int i=0; i<10000; ++i )
        bigbuffer[i] = 10;
    
    
    for( int n=0; n<10000; ++n )
        bigbuffer[n] *= 2; 
        
    std::cout<<"hello world" << std::endl;
}
