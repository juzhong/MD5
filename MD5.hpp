//
//  MD5.hpp
//  MD5
//
//  Created by juzhong on 16/2/16.
//  Copyright © 2016年 HUANG BINGDONG. All rights reserved.
//

#ifndef MD5_hpp
#define MD5_hpp

#include <stdio.h>
#include <string>

# if defined(__LP32__)
#  define LONG unsigned long
#  define LONG64 unsigned long long
# elif defined(__ILP64__)
#  define LONG unsigned long
#  define LONG64 unsigned long long
# else
#  define LONG unsigned int
#  define LONG64 unsigned long
# endif

class MD5
{
public:
    MD5(const char* message,size_t len);
    std::string hash;
private:
    LONG buff_h[4];
    void dealM(const char* m);
};

#endif /* MD5_hpp */
