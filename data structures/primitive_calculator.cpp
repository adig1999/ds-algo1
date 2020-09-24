#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
int minof2(int a, int b, int t)
{
    if(a<b)
    return t/2;
    else
    return t-1;
}
int minof(int a, int b, int t)
{
    if(a<b)
    return t/3;
    else
    return t-1;
}
int min(int a,int b,int c,int t)
{
    if(a<b)
    {
        if(a<c)
        return t/2;
        else
        return t-1;
    }
    else
    {
        if(b<c)
        return t/3;
        else
        return t-1;
    }
    
}

vector <int> optimal_sequence(int n) {
  std::vector<int> sequence;
  vector<int>minseq(n+1);
  minseq[0]=0;
  minseq[1]=1;
  int count=0;
  for(int i=2;i<n+1;i++)
  {
      int t=i;
    
        if(t%3==0 && t%2==0)
        {
        int prev=min(minseq[t/2],minseq[t/3],minseq[t-1],t);
           minseq[i]=minseq[prev]+1;
          }
        else if(t%3==0)
        {
            int prev2=minof(minseq[t/3],minseq[t-1],t);
            minseq[i]=minseq[prev2]+1;
        }
        else if(t%2==0)
        {
            int prev3=minof2(minseq[t/2],minseq[t-1],t);
            minseq[i]=minseq[prev3]+1;
        }
        else
        {
            minseq[i]=minseq[t-1]+1;
        }
  }
  int k=n;
  int curr;
 sequence.push_back(k);
  while(k!=1)
  {
      if(k%3==0 && k%2==0)
        {
        curr=min(minseq[k/2],minseq[k/3],minseq[k-1],k);
           
          }
        else if(k%3==0)
        {
            curr=minof(minseq[k/3],minseq[k-1],k);
            
        }
        else if(k%2==0)
        {
            curr=minof2(minseq[k/2],minseq[k-1],k);
           
        }
        else
        {
            curr=k-1;
        }
        sequence.push_back(curr);
        k=curr;
        
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
  
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
   
  
}


