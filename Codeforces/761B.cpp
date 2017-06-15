#include <bits/stdc++.h>

using namespace std;

int a[60],b[60];
int bar_flag[200];

int main()
{
    int n,l,num;

    cin>>n>>l;

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    bar_flag[1] = 2;

    for(int i=0; i<n; i++)
    {
        cin>>num;

        if(1 + num > l)
            bar_flag[ (1 + num) % l ] = 1;
        else
            bar_flag[ 1 + num ] = 1;
        //cout<<1 + (num % l)<<endl;
    }

    int flag = 0,cnt;

    for(int i=1; i<=l; i++)
    {
        cnt = 0;


        if(cnt == n)
        {
            flag = 1;
            break;
        }
    }
    if(flag)
    {
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;

    return 0;
}
