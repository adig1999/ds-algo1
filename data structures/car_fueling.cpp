#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops,int n) {
    int pos=0;
    int refil=0;
    int i;
    vector<int>stop(n+2);
    stop[0]=0;
    stop[n+1]=dist;
    
    for(i=1;i<n+1;i++)
    stop[i]=stops[i-1];
    
  
       for(i=0;i<n+2;i++)
       {
           if(stop[i]-stop[i-1]>tank)
           return -1;
           
           if((stop[i]-pos)>tank)
           {
               pos=stop[i-1];
               refil+=1;
           }
       }
       if((dist-pos)>tank)
       return -1;

   
    return refil;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops,n) << "\n";

    return 0;
}

