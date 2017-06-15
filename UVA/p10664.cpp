#include <bits/stdc++.h>

using namespace std;

int wt[100],amnt,dp[200][200];

/*

*/

int knapsack(int i,int W)
{
    if(i == 0)
    {
        return 0;//i er value 0 er niche chole jete pare..tai ekta base case dhrlam jekhane return 0 dibe..
    }

    if(dp[ i ][ W ] != -1)
    {
        return dp[ i ][ W ];
    }

    if(wt[ i ] > W)
    {
        dp[ i ][ W ] = knapsack( i-1 , W );
    }
    else
    {
        dp[ i ][ W ] = max( knapsack( i-1 , W), wt[i] + knapsack( i-1 , W - wt[i] ) );
    }

    return dp[ i ][ W ];

}

int main()
{
    int tst;
    string s;

    scanf("%d",&tst);
    getchar();

    for(int i=0; i<tst; i++)
    {
        getline(cin,s);

        stringstream b(s);
        int k = 1;
        int a;

        amnt = 0;

        while(b>>a)
        {
            wt[k] = a;
            amnt += wt[k];
            k++;
        }

        if((amnt % 2) != 0)
        {
            printf("NO\n");
        }
        else
        {
            amnt = amnt / 2;

            k-=1;

            for(int i=0; i<=k; i++)
            {
                for(int j=0; j<=amnt; j++)
                {
                    dp[i][j] = -1;
                }
            }

            int res = knapsack(k,amnt);

            if( res == amnt )
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }


        }

    }


    return 0;
}
