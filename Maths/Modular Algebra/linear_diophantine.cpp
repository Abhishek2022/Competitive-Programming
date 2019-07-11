/* LINEAR DIOPHANTINE EQUATIONS

Equation: ax+by=c
1. No Solution: 
    -- c is not a multiple of g (g = gcd(a,b))

2. All Solutions: 
    -- First find x0 and y0 where x0 = x*c/g and y0=y*c/g
    -- All other solutions will be of the form 
        x0 = x0 + k*b/g
        y0 = y0 - k*a/g

3. Solution in a range (minx,miny) to (maxx,maxy):
    -- Adjust x such that lx1>=minx and rx1<=maxx
    -- Adjust y such that y1>=miny and y2<=maxy and not corresponding lx2, rx2
    -- Final range = intersection((lx1,rx1),(lx2,rx2))
    -- No. of solutions = (length of range)/b + 1

4. Solution with minimum (x+y):
    -- There has to be some restriction or the ans will be -inf.
    -- x0 + y0 = x + y + k*(b-a)/g
    -- if(b>a) choose minimum possible k
    -- if(a>b) choose maximum possible k
    !! CORNER CASE: a = b = 0;

5. Positive solutions of Diophantine Equations:
    -- If either a or b is less than 0, there are infite solutions
    -- x0 = x*c/g + k*b/g   AND   y0 = y*c/g - k*a/g  
    -- x*c + k*b > 0    AND     y*c - k*a > 0
    -- (-x*c/abs(b)) < k < (y*c/abs(a))

6. CHICKEN McNUGGET THEOREM
    -- For any a,b where gcd(a,b) = 1, the largest number that cannot be written of the form
    ax + by is ab-a-b (!!GIVEN x and y are positive)
    -- Hence ax + by = k always has a positive solution for k > (ab-a-b)
 */



int gcdExtended(int a, int b, int &x, int &y) 
{
    if (a == 0) 
    {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcdExtended(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0) 
{
    int g;
    g = gcdExtended(abs(a), abs(b), x0, y0);

    if (c % g) 
        return false;
    
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

//Shifts solution
void shift_solution(int & x, int & y, int a, int b, int cnt) 
{
    x += cnt * b;
    y -= cnt * a;
}

//Finding all solutions in a given range
int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) 
{
    int x, y, g;
    g = gcdExtended(a,b,x,y);
    if (!find_any_solution(a, b, c, x, y))
        return 0;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}