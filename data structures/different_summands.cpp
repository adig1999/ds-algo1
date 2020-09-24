#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int k=1;
  
  if(n==2)
  {
  summands.push_back(2);
  return summands;
  }
  summands.push_back(1);
  int sum=1;
  
  while(sum!=n)
  {
      if(((sum+k<n-summands.back()-1)||(sum+k==n))&&(k!=summands.back()))
      {
         sum+=k;
          summands.push_back(k);
      }
      k++;
  }
  
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}