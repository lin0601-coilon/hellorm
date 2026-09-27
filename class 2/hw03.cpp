// hw03
#include <iostream>
#include <iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  long long sum=0;
  for (int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    sum=sum+x;
    if (i>0)
    {
      cout<< " ";
    }
    cout<<sum;
  }
  cout<<endl;
  return 0;
  }



