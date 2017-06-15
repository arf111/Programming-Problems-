#include <bits/stdc++.h>

using namespace std;

map<int,int> freq;

int main()
{
    int n,num,flag = 0;

    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
       scanf("%d",&num);

       freq[num]++;

       if(freq[num] > 1)
       {
          flag = 1;
       }
    }

    if(flag)
    {
        printf("NO\n");
    }
    else
        printf("YES\n");

    return 0;
}
