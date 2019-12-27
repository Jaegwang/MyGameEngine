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

int main( const int argc, const char** argv )
{

    ShortString<> a("abcgd");
    ShortString<> b("abceg");

    bool check = a != b;
    
    std::cout<< check << std::endl;
    
    std::cout<<"hello world" << std::endl;
}
