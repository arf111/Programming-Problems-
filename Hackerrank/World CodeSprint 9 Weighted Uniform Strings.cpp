#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
   set<ll> myset;
   string str;
   char prev;
   ll prevvalue,queries;

   getline(cin,str);

   prev = str[0];

   myset.insert( (prev - 'a') + 1);

   prevvalue = (prev - 'a') + 1;

   for(int i=1; i<str.size(); i++)
   {
       if(str[i] == prev)
       {
           prevvalue += (str[i] - 'a') + 1;

           myset.insert(prevvalue);

           prev = str[i];
       }
       else
       {
           myset.insert( (str[i] - 'a') + 1);

           prevvalue = (str[i] - 'a') + 1;

           prev = str[i];
       }
   }
   ll num;

   scanf("%lld",&queries);

   for(int i=0; i<queries; i++)
   {
        scanf("%lld",&num);

        if(myset.find(num) != myset.end())
        {
            printf("Yes\n");
        }
        else
            printf("No\n");
   }


   return 0;
}
