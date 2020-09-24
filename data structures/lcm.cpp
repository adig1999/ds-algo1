#include <iostream>

long long gcd_fast(long long a, long long b) {
  if(a>b)
{
if(b==0)
return a;
else
return gcd_fast(b,a%b);
}
else if(a<b)
{
if(a==0)
return b;
else
return gcd_fast(a,b%a);
}
}

int main() {
  long long a, b;
  long long lcm;
  
  std::cin >> a >> b;
  lcm=(a*b)/gcd_fast(a,b);
  std::cout <<lcm<< std::endl;
  return 0;
}