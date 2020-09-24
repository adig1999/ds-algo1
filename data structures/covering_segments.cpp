#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using
  std::vector;

struct Segment
{
  int
    start,
    end;
};

bool
compareint (Segment &a, Segment &b)
{
  return a.end < b.end;
}

vector < int >
optimal_points (vector < Segment > &segments)
{
  vector < int >
    points;
  int
    i;
  std::sort (segments.begin(), segments.end(), compareint);
  
 int  curr = -1;


  for (size_t i =0 ; i < segments.size (); ++i)
    {
      if (curr < segments[i].start)
	{
	  points.push_back (segments[i].end);
	  curr = segments[i].end;
	}
    }
  return points;
}

int
main ()
{
  int
    n;
  std::cin >> n;
  vector < Segment > segments (n);
  for (size_t i = 0; i < segments.size (); ++i)
    {
      std::cin >> segments[i].start >> segments[i].end;
    }
  vector < int >
    points = optimal_points (segments);
  std::cout << points.size () << "\n";
  for (size_t i = 0; i < points.size (); ++i)
    {
      std::cout << points[i] << " ";
    }
}
