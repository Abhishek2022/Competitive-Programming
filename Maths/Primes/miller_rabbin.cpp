//MILLER RABBIN CODE

long long binPow(long long a, long long b, long long p ) 
{
    if (b == 0)
        return 1;
    long long res = binPow(a, b/2,p);
    if (b % 2)
        return (res*res*a)%p;
    else
        return (res*res)%p;
}

bool checkComp(long long n, long long a,long long d, long long s)
{
    long long x = binPow(a,d,n);
    if(x==1 || x==n-1)
        return false;
    for(int i=1;i<s;i++)
    {
        x = (x*x)%n;
        if(x==n-1)
            return false;
    }
    return true;
}

bool miller(long long n)
{
    if(n<2)
        return false;
    long long r = 0;
    long long d = n-1;
    while((d & 1)==0)
    {
        r++;
        d>>=1;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) 
    {
        if (n == a)
            return true;
        if (checkComp(n, a, d, r))
            return false;
    }
    return true;
}

//----------------------------------------------------------------------------------

//MILLER RABBIN - BOOST LIBRARY

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) 
{
    u64 result = 1;
    base %= mod;
    while (e) 
    {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) 
{
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) 
    {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool MillerRabin(u64 n) 
{
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) 
    {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) 
    {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}