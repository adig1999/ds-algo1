#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using
  std::vector;
  
  double min(double a,double b){
      if(a>b)
      return b;
       else
     return a;
  }

double
get_optimal_value (double capacity, vector < double >weights, vector < double >values,
		   int n)
{
    double c= capacity;
     
  double
    value = 0.0;
  vector < double >a (n);
 double
    i,
    j,t=0,w,sum1=0,sum2=0;
    
   
  for (i = 0; i < n; i++)
    {
      a[i] = ((double)values[i]) / weights[i];
sum1=sum1+weights[i];
    }
    
    if(sum1<=capacity)
    {
        for(i=0;i<n;i++)
        value=value+values[i];
        return value;
    }

  while(c!=0)
  {
      t=-1;
      for(i=0;i<n;i++)
      {
          
         if(weights[i]>0 && (a[i]>a[t]))
          {
              t=i;
          }
         
         
      }
     w=min(weights[t],c);
      c=c-w;
      value=value+((double)w)*a[t];
      weights[t]=weights[t]-w;
  }
    

  return value;
}

int
main ()
{
  int
    n;
  double
    capacity;
  std::cin >> n >> capacity;
  vector < double > values (n);
  vector < double > weights (n);
  for (int i = 0; i < n; i++)
    {
      std::cin >> values[i] >> weights[i];
    }

  double
    optimal_value = get_optimal_value (capacity, weights, values, n);

  std::cout.precision (10);
  std::cout << optimal_value << std::endl;
  return 0;
}

