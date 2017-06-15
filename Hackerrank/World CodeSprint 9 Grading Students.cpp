#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,num;

    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
       scanf("%d",&num);

       if(num < 38)
       {
          printf("%d\n",num);
       }
       else
       {
           int divid = (num / 5) + 1;

           if( (divid * 5) - num < 3 )
           {
              printf("%d\n",divid*5);
           }
           else
           {
               printf("%d\n",num);
           }
       }
    }


    return 0;
}
