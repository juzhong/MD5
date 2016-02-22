//
//  md5Test.cpp
//  MD5
//
//  Created by juzhong on 16/2/16.
//  Copyright © 2016年 HUANG BINGDONG. All rights reserved.
//


#include <iostream>
#include <string>
#include "MD5.hpp"

int main(int argc, const char * argv[])
{
    std::string message = "Hello,world!";
    
    std::cout<<"message's MD5:"<<MD5(message.c_str(),message.length()).hash<<std::endl;
    
    return 0;
}

