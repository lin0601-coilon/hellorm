//hw04
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
 double sum=0;
 double socre;
 double max_socre=0;
 double min_socre=100;
 for (int i=1;i<=5;i++)
 {
  cin>>socre;
  sum=sum+socre;
  if (socre>max_socre)
  {
   max_socre=socre;
  }
  if (socre<min_socre)
  {
   min_socre=socre;
  }
 }
 double avg=(sum-max_socre-min_socre)/(3);
 cout<<setprecision(2)<<fixed<<avg<<endl;
 return 0;
}