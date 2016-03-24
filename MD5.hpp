//
//  MD5.hpp
//  MD5
//
//  Created by juzhong on 16/2/16.
//  Copyright © 2016年 HUANG BINGDONG. All rights reserved.
//

//Warning: this class calculate md5 hash on some platform is error!If you import this class to your project,please test the hash
//         whether or not is right which calculate by this class.          

#ifndef MD5_hpp
#define MD5_hpp

#include <stdio.h>
#include <string>

//following macro is using for cross platform,but it has a bug,lead to on some platform calculate md5 hash is wrong!
//such as Mac OS X Simulator for iPhone 5(this is not arm64 platform)
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
