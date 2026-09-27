//hw05
#include <iostream>
using namespace std;
int main()
{
    int arr[100];
    int x;
    int cnt=0;
    while (cin>>x&&x!=0)
    {
        arr[cnt]=x;
        cnt++;
    }
    for (int i=cnt-1;i>=0;i--)
    {
       if (i!=cnt-1)cout<<" ";
        cout<<arr[i];
    }
    cout<<endl;
    return 0;
}