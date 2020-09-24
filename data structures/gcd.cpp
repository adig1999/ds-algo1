#include <iostream>

int gcd_fast(int a, int b) {
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
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
