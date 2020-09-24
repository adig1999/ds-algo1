#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  int i,j;
int temp=0;

 
  for(j=0;j<a.size()-1;j++)
  {
      for(i=0;i<a.size()-j-1;i++)
      {
          if(a[i]>a[i+1])
          {
          temp=a[i];
          a[i]=a[i+1];
          a[i+1]=temp;
          }
      }
  }
  
  for(j=0;j<b.size()-1;j++)
  {
      for(i=0;i<b.size()-j-1;i++)
      {
          if(b[i]>b[i+1])
          {
          temp=b[i];
          b[i]=b[i+1];
          b[i+1]=temp;
          }
      }
  }

  
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}

