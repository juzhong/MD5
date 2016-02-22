//
//  MD5.cpp
//  MD5
//
//  Created by juzhong on 16/2/16.
//  Copyright © 2016年 HUANG BINGDONG. All rights reserved.
//

#include "MD5.hpp"
#include <string.h>

#define ZEN_SWAP_UINT32_L(x)  ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) | \
(((x) & 0x0000ff00) <<  8) | (((x) & 0x000000ff) << 24))
#define ZEN_SWAP_UINT32(x)  (x)


//#define ZEN_SWAP_UINT64(x)  ((((x) & 0xff00000000000000) >> 56) | (((x) & 0x00ff000000000000) >>  40) | \
//(((x) & 0x0000ff0000000000) >> 24) | (((x) & 0x000000ff00000000) >>  8) | \
//(((x) & 0x00000000ff000000) << 8 ) | (((x) & 0x0000000000ff0000) <<  24) | \
//(((x) & 0x000000000000ff00) << 40 ) | (((x) & 0x00000000000000ff) <<  56))

#define ZEN_SWAP_UINT64(x) (x)

inline LONG F(LONG x,LONG y,LONG z)
{
    
    return (x&y) |((~x)&z);
}

inline LONG G(LONG x,LONG y,LONG z)
{
    return (x&z) |(y&(~z));
}

inline LONG H(LONG x,LONG y,LONG z)
{
    return x^y^z;
}
inline LONG I(LONG x,LONG y,LONG z)
{
    return y^(x|(~z));
}


inline LONG S(int n,LONG x)
{
    return (x<<n)|(x>>(32-n));
}


#define FF(a,b,c,d,M,s,t)  (a) = (b) + S((s),((a) + F((b),(c),(d)) + (M) + (t)));
#define GG(a,b,c,d,M,s,t)  (a) = (b) + S((s),((a) + G((b),(c),(d)) + (M) + (t)));
#define HH(a,b,c,d,M,s,t)  (a) = (b) + S((s),((a) + H((b),(c),(d)) + (M) + (t)));
#define II(a,b,c,d,M,s,t)  (a) = (b) + S((s),((a) + I((b),(c),(d)) + (M) + (t)));



void MD5::dealM(const char* m)
{
    LONG a,b,c,d;
    a=buff_h[0],b=buff_h[1],c=buff_h[2],d=buff_h[3];
    
    LONG M0=ZEN_SWAP_UINT32(*((LONG *)m+0));
    LONG M1=ZEN_SWAP_UINT32(*((LONG *)m+1));
    LONG M2=ZEN_SWAP_UINT32(*((LONG *)m+2));
    LONG M3=ZEN_SWAP_UINT32(*((LONG *)m+3));
    LONG M4=ZEN_SWAP_UINT32(*((LONG *)m+4));
    LONG M5=ZEN_SWAP_UINT32(*((LONG *)m+5));
    LONG M6=ZEN_SWAP_UINT32(*((LONG *)m+6));
    LONG M7=ZEN_SWAP_UINT32(*((LONG *)m+7));
    LONG M8=ZEN_SWAP_UINT32(*((LONG *)m+8));
    LONG M9=ZEN_SWAP_UINT32(*((LONG *)m+9));
    LONG M10=ZEN_SWAP_UINT32(*((LONG *)m+10));
    LONG M11=ZEN_SWAP_UINT32(*((LONG *)m+11));
    LONG M12=ZEN_SWAP_UINT32(*((LONG *)m+12));
    LONG M13=ZEN_SWAP_UINT32(*((LONG *)m+13));
    LONG M14=ZEN_SWAP_UINT32(*((LONG *)m+14));
    LONG M15=ZEN_SWAP_UINT32(*((LONG *)m+15));
    
    FF(a ,b ,c ,d ,M0 ,7 ,0xd76aa478 )
    FF(d ,a ,b ,c ,M1 ,12 ,0xe8c7b756 )
    FF(c ,d ,a ,b ,M2 ,17 ,0x242070db )
    FF(b ,c ,d ,a ,M3 ,22 ,0xc1bdceee )
    FF(a ,b ,c ,d ,M4 ,7 ,0xf57c0faf )
    FF(d ,a ,b ,c ,M5 ,12 ,0x4787c62a )
    FF(c ,d ,a ,b ,M6 ,17 ,0xa8304613 )
    FF(b ,c ,d ,a ,M7 ,22 ,0xfd469501)
    FF(a ,b ,c ,d ,M8 ,7 ,0x698098d8 )
    FF(d ,a ,b ,c ,M9 ,12 ,0x8b44f7af )
    FF(c ,d ,a ,b ,M10 ,17 ,0xffff5bb1 )
    FF(b ,c ,d ,a ,M11 ,22 ,0x895cd7be )
    FF(a ,b ,c ,d ,M12 ,7 ,0x6b901122 )
    FF(d ,a ,b ,c ,M13 ,12 ,0xfd987193 )
    FF(c ,d ,a ,b ,M14 ,17 ,0xa679438e )
    FF(b ,c ,d ,a ,M15 ,22 ,0x49b40821 )
    
    GG(a ,b ,c ,d ,M1 ,5 ,0xf61e2562 )
    GG(d ,a ,b ,c ,M6 ,9 ,0xc040b340 )
    GG(c ,d ,a ,b ,M11 ,14 ,0x265e5a51 )
    GG(b ,c ,d ,a ,M0 ,20 ,0xe9b6c7aa )
    GG(a ,b ,c ,d ,M5 ,5 ,0xd62f105d )
    GG(d ,a ,b ,c ,M10 ,9 ,0x02441453 )
    GG(c ,d ,a ,b ,M15 ,14 ,0xd8a1e681 )
    GG(b ,c ,d ,a ,M4 ,20 ,0xe7d3fbc8 )
    GG(a ,b ,c ,d ,M9 ,5 ,0x21e1cde6 )
    GG(d ,a ,b ,c ,M14 ,9 ,0xc33707d6 )
    GG(c ,d ,a ,b ,M3 ,14 ,0xf4d50d87 )
    GG(b ,c ,d ,a ,M8 ,20 ,0x455a14ed )
    GG(a ,b ,c ,d ,M13 ,5 ,0xa9e3e905 )
    GG(d ,a ,b ,c ,M2 ,9 ,0xfcefa3f8 )
    GG(c ,d ,a ,b ,M7 ,14 ,0x676f02d9 )
    GG(b ,c ,d ,a ,M12 ,20 ,0x8d2a4c8a )
    
    HH(a ,b ,c ,d ,M5 ,4 ,0xfffa3942 )
    HH(d ,a ,b ,c ,M8 ,11 ,0x8771f681 )
    HH(c ,d ,a ,b ,M11 ,16 ,0x6d9d6122 )
    HH(b ,c ,d ,a ,M14 ,23 ,0xfde5380c )
    HH(a ,b ,c ,d ,M1 ,4 ,0xa4beea44 )
    HH(d ,a ,b ,c ,M4 ,11 ,0x4bdecfa9 )
    HH(c ,d ,a ,b ,M7 ,16 ,0xf6bb4b60 )
    HH(b ,c ,d ,a ,M10 ,23 ,0xbebfbc70 )
    HH(a ,b ,c ,d ,M13 ,4 ,0x289b7ec6 )
    HH(d ,a ,b ,c ,M0 ,11 ,0xeaa127fa )
    HH(c ,d ,a ,b ,M3 ,16 ,0xd4ef3085 )
    HH(b ,c ,d ,a ,M6 ,23 ,0x04881d05 )
    HH(a ,b ,c ,d ,M9 ,4 ,0xd9d4d039 )
    HH(d ,a ,b ,c ,M12 ,11 ,0xe6db99e5 )
    HH(c ,d ,a ,b ,M15 ,16 ,0x1fa27cf8 )
    HH(b ,c ,d ,a ,M2 ,23 ,0xc4ac5665 )
    
    II(a ,b ,c ,d ,M0 ,6 ,0xf4292244 )
    II(d ,a ,b ,c ,M7 ,10 ,0x432aff97 )
    II(c ,d ,a ,b ,M14 ,15 ,0xab9423a7 )
    II(b ,c ,d ,a ,M5 ,21 ,0xfc93a039 )
    II(a ,b ,c ,d ,M12 ,6 ,0x655b59c3 )
    II(d ,a ,b ,c ,M3 ,10 ,0x8f0ccc92 )
    II(c ,d ,a ,b ,M10 ,15 ,0xffeff47d )
    II(b ,c ,d ,a ,M1 ,21 ,0x85845dd1 )
    II(a ,b ,c ,d ,M8 ,6 ,0x6fa87e4f )
    II(d ,a ,b ,c ,M15 ,10 ,0xfe2ce6e0 )
    II(c ,d ,a ,b ,M6 ,15 ,0xa3014314 )
    II(b ,c ,d ,a ,M13 ,21 ,0x4e0811a1 )
    II(a ,b ,c ,d ,M4 ,6 ,0xf7537e82 )
    II(d ,a ,b ,c ,M11 ,10 ,0xbd3af235 )
    II(c ,d ,a ,b ,M2 ,15 ,0x2ad7d2bb )
    II(b ,c ,d ,a ,M9 ,21 ,0xeb86d391 )
    
    buff_h[0] = buff_h[0]+a,
    buff_h[1] = buff_h[1]+b,
    buff_h[2] = buff_h[2]+c,
    buff_h[3] = buff_h[3]+d;
}



MD5::MD5(const char* message,size_t len)
{
    buff_h[0]=0x67452301;
    buff_h[1]=0xEFCDAB89;
    buff_h[2]=0x98BADCFE;
    buff_h[3]=0x10325476;
    
    int r = len%64;
    size_t blocks = len/64;
    int addlen = 0;
    if (r==56) {
        addlen = 64+8;
    }else if (r<56)
    {
        addlen = 56-r+8;
    }else
    {
        addlen = 64-r+64;
    }
    
    char roundmessage[r+addlen];
    memset(roundmessage, 0, r+addlen);
    memcpy(roundmessage, message+64*blocks, r);
    roundmessage[r] =0x80;
    
    unsigned long *length = (unsigned long *)roundmessage+(r+addlen)/8-1;
    unsigned long x = ZEN_SWAP_UINT64(len*8);
    *length =x;
    
    for (int i = 0; i<blocks; i++) {
        dealM(message+i*64);
    }
    
    for (int i = 0; i<(r+addlen)/64; i++) {
        dealM(roundmessage+i*64);
    }
    
    char _hash[33];
    
    buff_h[0] = ZEN_SWAP_UINT32_L(buff_h[0]);
    buff_h[1] = ZEN_SWAP_UINT32_L(buff_h[1]);
    buff_h[2] = ZEN_SWAP_UINT32_L(buff_h[2]);
    buff_h[3] = ZEN_SWAP_UINT32_L(buff_h[3]);
    
    sprintf(_hash, "%08x%08x%08x%08x",(LONG)buff_h[0],(LONG)buff_h[1],(LONG)buff_h[2],(LONG)buff_h[3]);
    hash = _hash;

}
