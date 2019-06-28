//NUMBER OF PRIME FACTORS

//-- Modify sieve to store number of prime factors
//-- factors(12) = {2,3}

vector<int> prime(1000001,0)
void factors(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==0)
        {
            for(int p=i;p<=n;p+=i)
                prime[p]++;
        }
    }
}