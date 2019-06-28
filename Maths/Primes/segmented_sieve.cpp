//SEGMENTED SIEVE

//-- When sieve cannot store enough prime numbers.
//-- We generate primes only till sqrt(n).
//-- Use the generated primes to mark primes in given range.

vi primes;
vector<bool> is_prime(100001,1);
void sieveGenerate(int n)
{
    int temp = sqrt(n);
    for(int i=2;i<=temp;i++)
    {
        if(is_prime[i])
        {
            for(int p=i*i;p<=n;p+=i)
                is_prime[p] = 0;
        }
    }
    
    primes.pb(2);
    for(int i=3;i<=n;i+=2)
    {
        if(is_prime[i])
            primes.pb(i);
    }
}

void segmentedSieve(long long a, long long b)
{
    int k = sqrt(b);
    vector<bool> range(b-a+1,1);
    for(int i: primes)
    {
        if(i>k)
            break;
        long long temp = (a/i)*i;
        if(temp<a)
            temp+=i;

        for(long long p=temp;p<=b;p+=i)
            range[p-a] = 0;
        if(temp == i)	
            range[temp-a] = 1;
    }

    for(ll i=0;i<=b-a;i++)
        if(range[i] && (i+a)!=1)
            cout<<i+a<<"\n";
}