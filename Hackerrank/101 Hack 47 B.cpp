#include <bits/stdc++.h>

using namespace std;

int flag[5000];

int main()
{
    int n,p,q;

    scanf("%d %d %d",&n,&p,&q);

    vector<int> a(p);

    for(int a_i = 0; a_i < p; a_i++)
    {
        cin >> a[a_i];
    }

    vector<int> b(q);

    for(int b_i = 0; b_i < q; b_i++)
    {
        cin >> b[b_i];
    }

    int sop = 1;

    for(int i=0; i<p; i++)
    {
        for(int j=0; j<q; j++)
        {

            int rem = (a[i] + b[j] ) / n;

            rem += 1;

            int divid = rem * n;

            int dnttake = divid -( a[i] + b[j] );

            flag[dnttake] = 1;

        }
    }

    while(1)
    {
        if(flag[sop])
        {
            sop++;
        }
        else
        {
            break;
        }
    }

    printf("%d\n",sop);

    return 0;
}
