#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m;
// a 2d matrix class
// operator overriding for mutiplication of a 2*2 matrix
// matrix is of the form a b
//                       c d
struct mat
{
	ll a, b, c, d;
	mat operator*(mat &t)
	{
		mat ans;
		ans.a = ((a * t.a) % m + (b * t.c) % m) % m;
		ans.b = ((a * t.b) % m + (b * t.d) % m) % m;
		ans.c = ((c * t.a) % m + (d * t.c) % m) % m;
		ans.d = ((c * t.b) % m + (d * t.d) % m) % m;
		return ans;
	}
};
void printer(mat &T)
{
	cout << T.a << " " << T.b << "\n";
	cout << T.c << " " << T.d << "\n\n";
}
mat power(ll n)
{
	mat ans = {1, 0, 0, 1};
	mat T = {0, 1, 1, 1};
	while (n)
	{
		if (n & 1)
			ans = ans * T;
		n >>= 1;
		T = T * T;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n;
	cin >> n >> m;
	mat ans = power(n);
	cout << ans.b;
	return 0;
}