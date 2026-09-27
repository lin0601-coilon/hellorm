//hw06
#include<iostream>
#include<string>
using namespace std;
int main() {
    string s;
    cin>>s;
    int x=0,y=0;
    for (int i=0;i<s.size();i++) {
        char c = s[i];
        if (c=='U')
        {
            y++;
        }
        else if (c=='D')
        {
            y--;
        }

        else if (c=='L')
        {
            x--;
        }
        else if (c=='R')
        {
            x++;
        }
    }
    if (x==0&&y==0)
    {
        cout<<"true"<<endl;
    }
    else
    {
    cout<<"false"<<endl;
    }
    return 0;

}
