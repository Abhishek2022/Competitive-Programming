/* CALCULATING nCr

--Using the identity nCr = (n-1)C(r-1) + (n-1)Cr.
--Storing the previous calculated values of nCr.
--This is faster when we need to calculate a large number of combinations, else using prod((i+r)/i) would be faster.
*/

#include <bits/stdc++.h>
using namespace std;

long long c[1000][1000];
int comb(int n, int r)
{
    if(r==0 || n==r)
    {
        c[n][r] = 1;
        return 1;
    }
    else
    {
        if(c[n-1][r-1]==0)
            c[n-1][r-1] = c[n-1][n-r] = comb(n-1,r-1)%1000000007;
        
        if(c[n-1][r]==0)
            c[n-1][r] = c[n-1][n-r-1] = comb(n-1,r)%1000000007;
    }
    return (c[n-1][r] + c[n-1][r-1])%1000000007;
}