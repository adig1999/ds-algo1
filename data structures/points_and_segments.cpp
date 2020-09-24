#include <bits/stdc++.h>

using std::vector;
struct segment
{
    int starts;
    int ends;

};

bool mycmp(segment &a,segment &b)
{
    return a.starts<b.starts;
}
vector<int> fast_count_segments(vector<segment>seg, vector<int> points) {
    vector<int> cnt(points.size());

  std::sort(seg.begin(),seg.end(),mycmp);

  for(int j=0;j<points.size();j++)
  {
      for(int i=0;i<seg.size();i++)
      {
          //if(seg[i].starts==seg[i-1].starts && seg[i].ends==seg[i-1].ends)
          //break;

          if(points[j]>=seg[i].starts && points[j]<=seg[i].ends)
          {

              cnt[j]++;
          }
          if(points[j]<seg[i].starts)
            break;
      }
  }

  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
 vector<segment>seg(n);

 for(int i=0;i<n;i++)
 {
     std::cin>>seg[i].starts>>seg[i].ends;
 }

  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(seg, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
