#include <bits/stdc++.h>
#define ll long long

using namespace std;

int coins[200],dp[200][27000];

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

    if( coins[ i ] <= W )
    {
         dp[ i ][ W ] = max( knapsack( i-1 , W ) , coins[ i ] + knapsack( i-1 , W - coins[ i ]  ) );
    }
    else
    {
         dp[ i ][ W ] = knapsack( i-1 , W );
    }

    return dp[ i ][ W ];
}

int main()
{
    int tc,n;

    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d",&n);

        int amnt = 0;

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&coins[i]);
            amnt += coins[i];
        }

        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=(amnt/2); j++)
            {
                dp[i][j] = -1;
            }
        }

        int res = knapsack(n,amnt/2);

        printf("%d\n",res);

        int diff = amnt - ( 2 * res );

        printf("%d\n",diff);

    }


    return 0;
}
