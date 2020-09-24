#include <iostream>
#include <string>
#include <cstring>

using std::string;
int minof(int a,int b,int c)
{
    int min;
    if(a<b)
    {
        if(a<c)
        return a;
        else
        return c;
    }
    else 
    {
        if(b<c)
        return b;
        else
        return c;
    }
    
}
int edit_distance(const string &str1, const string &str2) {
  int k=str1.size();
  int t=str2.size();
  
  int insertion,deletion,match,mismatch;
  
  int d[k+1][t+1];
  for(int i=0;i<k+1;i++)
      {
        d[i][0]=i;
      }
  for(int j=0;j<t+1;j++)
      {
       d[0][j]=j;   
      }
      for(int j=1;j<t+1;j++)
      {
          for(int i=1;i<k+1;i++)
          {
              insertion=d[i][j-1]+1;
              deletion=d[i-1][j]+1;
              match=d[i-1][j-1];
              mismatch=d[i-1][j-1]+1;
              if(str1[i-1]==str2[j-1])
              {
                  d[i][j]=minof(insertion,deletion,match);
              }
              else
              {
                  d[i][j]=minof(insertion,deletion,mismatch);
              }
          }
      }
      
  
  return d[k][t];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}

