#include <bits/stdc++.h>

using std::vector;



int optimal_weight(int W,  vector<int> &w) {

  w.insert(w.begin(),0);

 int t=w.size();
vector<vector<int> >arr(W+1,vector<int>(t,0));

 for(int i=0;i<=W;i++)
    arr[i][0]=0;

    for(int i=0;i<t;i++)
        arr[0][i]=0;

    int weight=0;

    for(int j=1;j<t;j++)
    {
        for(int i=1;i<=W;i++)
        {
            arr[i][j]=arr[i][j-1];
            if(w[j]<=i)
            {
                weight=arr[i-w[j]][j-1]+w[j];
                if(arr[i][j]<weight)
                {
                    arr[i][j]=weight;
                }
            }
        }
    }
;

  return arr[W][t-1];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}