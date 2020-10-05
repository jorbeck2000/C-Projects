#include <iostream>
#include <map>
using namespace std;
//recursividad
 int fibonacci(int n)//------->O=2^n
{
    if (n < 0)
        throw "illegal negative number";

    if (n < 2)
        return n;
    
    return fibonacci(n-1) + fibonacci(n-2);
}

// con memoria
int fibonacci_v2(int n, map<int, int> &cache)//-------->O=2^n
{
    if (n < 0)//0(1)
        throw "illegal negative number";
    
    if (n < 2)//0(1)
        return n;

    if (cache.find(n) != cache.end())
        return cache[n];

    int val = fibonacci_v2(n-1, cache) + fibonacci_v2(n-2, cache);
    cache[n] = val;
    return val;
}
int fibonacci_iter(int n){ //--------->O=n
    int a=0, b=1, fib=0; //0(1)
    for (int i=0;i<n-1;i++) //0(n)
    {
        fib=a+b; //c1 0(1)
        a=b; //c2 0(1)
        b=fib; //c3 0(1)
    }
    return fib;
}


int main()
{
    int ans, nth;
    cout << "Enter an index for the Fibonacci sequence: ";
    cin >> nth;
    ans = fibonacci(nth);
    cout << ans << endl;


    map<int, int> cache;

    int ans2 = fibonacci_v2(nth, cache);
    cout << ans2 << endl;
    return 0;
}
