#include <iostream>
#include <vector>
#define ll long long
using std::vector;

int get_change(int m) {
  vector<ll>minmoney(m+1);
ll current;
vector<int>change(3);
change[0]=1;
change[1]=3;
change[2]=4;
for(int i=1;i<m+1;i++)
{
minmoney[i]=100000007;
}
minmoney[0]=0;
for(int i=1;i<=m;i++)
{
    for(int j=0;j<3;j++)
    {
        if((m>=change[j]) && (i-change[j])>=0)
        {
        current=minmoney[i-change[j]]+1;
        if(current<minmoney[i])
        {
            minmoney[i]=current;
        }
        }
    }
}

  return minmoney[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}