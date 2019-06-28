//LINEAR SIEVE

vector<long long >is_prime(1000001 , true);
vector<long long >prime;
vector<long long >spf(1000001);
  
void modifiedSieve(int N)
{
    is_prime[0] = is_prime[1] = false ;
    
    for (long long int i=2; i<N ; i++)
    {
        if (is_prime[i])
        {   
            prime.push_back(i);
            spf[i] = i;
        }
 
        for (long long int j=0;j<(int)prime.size()&&i*prime[j]<N && prime[j]<=spf[i];j++)
        {
            is_prime[i*prime[j]]=false;
            spf[i*prime[j]] = prime[j] ;
        }
    }
}
