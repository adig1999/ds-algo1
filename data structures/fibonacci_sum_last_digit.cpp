#include <bits/stdc++.h>

long long fibonacci_sum_fast(long long n) {
    if(n<=1)
        return n;
int i=0;
   long long f[60];
   long long sum;
f[0]=0;
f[1]=1;
if(n>1)
{
for(i=2;i<=60;i++)
{
f[i]=(f[i-1]+f[i-2])%10;
}
}
int k=(n+2)%60;
if(f[k]==0)
    sum=9;
else
    sum=f[k]-1;

    return sum;
}
int main() {
    long long n = 0;
    std::cin >> n;

    std::cout << fibonacci_sum_fast(n);
return 0;
}
