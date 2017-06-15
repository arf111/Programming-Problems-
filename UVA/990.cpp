#include <bits/stdc++.h>

using namespace std;

int dp[40][1500];

struct items{
   int d,val,weight;
}arr[40],result[40];

int knapsack(int i,int W)
{
    if(i == 0)
    {
       return 0;
    }

    if(dp[ i ][ W ] != -1)
    {
        return dp[ i ][ W ];
    }

    if(arr[i].weight <= W)
    {
        dp[ i ][ W ] = max( knapsack( i-1 , W ), arr[i].val + knapsack( i - 1 , W - arr[i].weight ) );
    }
    else
    {
        dp[ i ][ W ] = knapsack( i-1 , W );
    }

    return dp[ i ][ W ];
}

int main()
{
    int t,w,tc = 0;

    while(scanf("%d %d",&t,&w)!=EOF)
    {
        int n;

        if(tc++)
          printf("\n");

        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            scanf("%d %d",&arr[i].d,&arr[i].val);

            arr[i].weight = 3 * w * arr[i].d;
        }

        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=t; j++)
            {
                dp[i][j] = -1;
            }
        }

        printf( "%d\n" , knapsack(n,t) );

        int i = n,cnt = 0;

        while(i > 0 && dp[ i ][ t ] > 0)//dp[i][t] jokhn 0 hoye jabe tokhn bujhte hobe je weight nea shesh..
        {                               //tai dp[i][t] > 0 ..jotokhkhn weight = 0 na hoy totokhn item nea ta check korbo..

            if( dp[ i ][ t ] !=  dp[ i-1 ][ t ] )
            {

                  result[cnt].d = arr[i].d;

                  result[cnt].val = arr[i].val;

                  cnt++;

                  t -= arr[i].weight;
            }
            i--;
        }
        printf("%d\n",cnt);


        for(int i=cnt-1; i>=0; i--)
        {
            printf("%d %d\n", result[i].d , result[i].val);
        }
    }


    return 0;
}
