#include <iostream>
#include <cassert>
#include <string>
#include <vector>
 #define ll long long

using std::vector;
using std::string;
using std::max;
using std::min;

ll eval(ll a, ll b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

vector<ll> minandmax(int i,int j, vector<char>op,ll **m,ll **M)
{
ll maxf=-100000;
ll minf=1000000;

for(int t=i;t<j;t++)
{
    ll a=eval(M[i][t],M[t+1][j],op[t-1]);
    ll b=eval(M[i][t],m[t+1][j],op[t-1]);
   ll c=eval(m[i][t],M[t+1][j],op[t-1]);
    ll d=eval(m[i][t],m[t+1][j],op[t-1]);

    minf=min(minf,a);
    minf=min(minf,b);
    minf=min(minf,c);
    minf=min(minf,d);

    maxf=max(maxf,a);
    maxf=max(maxf,b);
    maxf=max(maxf,c);
    maxf=max(maxf,d);
}
vector<ll>z(2);
z[0]=minf;
z[1]=maxf;
return z;
}

long long get_maximum_value(const string &exp) {
    int i=0;
    vector<char>op;
    vector<ll>d;
 while(exp[i]!='\0')
 {
  if((exp[i]=='*')||(exp[i]=='+')||(exp[i]=='-')||(exp[i]=='/'))
     {
         op.push_back(exp[i]);
     }
     else
        d.push_back((exp[i]-48));
        i++;
 }
 int k=d.size();

ll **m=new ll *[k+1];
 for(int i=0;i<k+1;i++)
	{
		m[i]=new ll[k+1];
	}
	ll **M=new ll *[k+1];
 for(int i=0;i<k+1;i++)
	{
		M[i]=new ll[k+1];
	}

 for(i=0;i<=k;i++)
 {
     m[0][i]=m[i][0]=M[0][i]=M[i][0]=0;
 }

 for(i=1;i<=k;i++)
 {
     m[i][i]=M[i][i]=d[i-1];
 }
vector<ll>z(2);

 for(int s=1;s<k;s++)
 {
     for(i=1;i<=k-s;i++)
     {
         int j=i+s;
         z=minandmax(i,j,op,m,M);
         m[i][j]=z[0];
         M[i][j]=z[1];
     }
 }


  return M[1][k];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}


