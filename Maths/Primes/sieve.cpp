//SIEVE

vector<bool> is_prime(1000001,1);   
void sieveGenerate(int n) 
{      
    for (int p=2; p*p<=n; p++) 
    { 
       if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
}