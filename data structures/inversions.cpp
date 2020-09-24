#include<bits/stdc++.h>
using namespace std;
 
vector<int>a;
int merge_and_cnt(int s, int e)
{
 
    int m = (s + e) / 2;
    int i = s;
    int j = m + 1;
    vector<int>tmp;
 
    int inversions = 0;
 
    while (i < m + 1 && j < e + 1)
    {
        // = ensures that only inversions are counted if 
        // ai > bj and i < j
        // if you use =
        // ai >= bj and i < j
        if (a[i] <= a[j])
        {
            tmp.push_back(a[i]);
            i++;
        }
        else
        {
            // current elements that are in left part
            // stil not merged
            // are definitely greater than current element
            // e.g. [1, 4, 5] [3]
            // when merging the two parts, we have to add 2 for 3
            inversions += (m + 1 - i);
            tmp.push_back(a[j]);
            j++;
        }
    }
 
    while (i < m + 1)
    {

    }
 
    while (j < e + 1)
    {
        tmp.push_back(a[j]);
        j++;
    }
 
    for (int i = s; i <= e; i++)
        a[i] = tmp[i - s];
 
    return inversions;
}
 
int merge_sort(int s, int e)
{
    // if segment in consideration is 1 element
    // no inversions
    if (s == e)
        return 0;
    if (s < e)
    {
        int m = (s + e) / 2;
        // inversions of left part is in a
        int a = merge_sort(s, m);
        // inversions of right part is in b
        int b = merge_sort(m + 1, e);
        // inversions of both parts after merging is in c
        int c = merge_and_cnt(s, e);
        return a + b + c;
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n; cin >> n;
    a = vector<int>(n);
 
    for (auto &it : a)
        cin >> it;
 
    cout << merge_sort(0, n - 1) << endl;
 
   
 
    return 0;
}