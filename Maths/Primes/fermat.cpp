//FERMAT'S PROBABILISTIC TEST

long long binPow(long long a, long long b, long long m) 
{
    a %= m;
    long long res = 1;
    while (b > 0) 
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


bool fermat(long long n, int it)
{
    if(n<=4)
        return n==2||n==3;
    for(int i=0;i<it;i++)
    {
        int temp = 2 + rand()%(n-3);
        if (binPow(temp,n-1,n)!=1)
            return false;
    }
    return true;
}