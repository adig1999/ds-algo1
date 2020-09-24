#include <iostream>

int get_change(int m) {
  int n=0;
while(m!=0)
{
if(m>=10)
{
    m=m-10;
    n=n+1;
}
else if(m>=5)
{
    m=m-5;
    n=n+1;
}
else if(m>=1)
{
    m=m-1;
    n=n+1;
}
}

  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

