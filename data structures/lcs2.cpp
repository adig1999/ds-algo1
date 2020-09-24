#include <iostream>
#include <vector>

using std::vector;

int maxs(int a,int b,int c)
{
    if(a>b)
    {
        if(a>c)
            return a;
         else
            return c;

    }
    else
    {
        if(b>c)
            return b;
        else
            return c;
    }
}
int lcs2(vector<int> &a, vector<int> &b) {
  int t=a.size();
  int k=b.size();
  int arr[t+1][k+1];

  for(int i=0;i<=t;i++)
    arr[i][0]=0;
  for(int j=0;j<=k;j++)
    arr[0][j]=0;
int prev=0;
  for(int j=1;j<=k;j++)
  {

      for(int i=1;i<=t;i++)
      {
          if(a[i-1]==b[j-1]&&prev!=1)
          {
              arr[i][j]=arr[i-1][j-1]+1;
              
          }
          else
            arr[i][j]=std::max(arr[i][j-1],arr[i-1][j]);
       }
       
  }


  return arr[t][k];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}



