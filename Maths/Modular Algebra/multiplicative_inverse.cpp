/* MODULAR MULTIPLICATIVE INVERSE

--ax = 1(mod m)
--if m is prime, a*pow(a,m-2) = 1(mod m). Hence modInv(a,m) = pow(a,m-2)
*/

int gcdExtended(int a, int b, long long *x, long long *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    long long x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    *x = y1 - (b/a) * x1; 
    *y = x1;  
    return gcd; 
}   

int modInv(int a, int m) 
{ 
    long long x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    int res = (x%m + m) % m; 
    return res; 
} 
