#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
int mid=(left+right)/2;

std::sort(a.begin(),a.end());
int count=1;
while(a[mid]==a[mid+1])
{
    count+=1;
    mid=mid+1;
}
mid=(left+right)/2;
while(a[mid]==a[mid-1])
{
    count+=1;
    mid=mid-1;
    
}

if(count>(a.size()/2))
return 1;
else
return 0;

}

int main() {
  int n;
  int count=1;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size())) << '\n';
}