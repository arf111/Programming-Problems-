#include <bits/stdc++.h>
#define ll long long

using namespace std;

int dir_val[] = {0,0,0,0,0,0,0,0};

int main()
{
    int n,k,rq,cq,obsc,obsr;

    scanf("%d %d",&n,&k);

    scanf("%d %d",&rq,&cq);

    ///upor (n > rq) or ( obsr > rq && obsc == cq )
    dir_val[0] = ( n - rq );

    ///niche (rq > 1) or ( obsr < rq && obsc == cq )
    dir_val[1] = ( rq - 1 );

    ///left ( cq > 1 ) or ( obsr == rq && obsc < cq )
    dir_val[2] = ( cq - 1 );

    ///ri8 ( n > cq ) or ( obsr == rq && obsc > cq )
    dir_val[3] = ( n - cq );

    ///upor-left ( obsr - rq == cq - obsc )
    dir_val[4] = min( dir_val[0] , dir_val[2]);

    ///upor-right ( obsr - rq == obsc - cq )
    dir_val[5] = min( dir_val[0] , dir_val[3] );

    ///nicher-left ( rq - obsr == cq - obsc )
    dir_val[6] = min( dir_val[2],dir_val[1]);

    ///nicher-right ( rq - obsr == obsc - cq )
    dir_val[7] = min( dir_val[1],dir_val[3] );

    for(int i=0; i<k; i++)
    {
        cin>>obsr>>obsc;

        if(obsc == cq)
        {
            ///upore
            if(obsr > rq)
            {
               dir_val[0] = min( dir_val[0], (obsr - rq )-1);
            }
            ///niche
            if(obsr < rq)
            {
                dir_val[1] = min(dir_val[1], (rq - obsr)-1);
            }
        }
        else if(obsr == rq)
        {
            ///left
            if( obsc < cq )
            {
               dir_val[2] = min(dir_val[2] , ( cq - obsc )-1);
            }
            ///ri8
            if(obsc > cq)
            {
                dir_val[3] = min(dir_val[3], (obsc - cq)-1);
            }
        }
        ///upor-left
        else if(obsr > rq && cq > obsc && (obsr - rq == cq - obsc) )
        {
            dir_val[4] = min(dir_val[4], obsr - rq - 1 );
        }
        ///upor-ri8
        else if(obsr > rq && obsc > cq &&  (obsr - rq == obsc - cq) )
        {
            dir_val[5] = min(dir_val[5], obsr - rq - 1 );
        }
        ///nicher-left
        else if(rq > obsr && cq > obsc && (rq - obsr == cq - obsc) )
        {
            dir_val[6] = min(dir_val[6],rq-obsr-1);
        }
        ///nicher-right
        else if(rq > obsr && obsc > cq &&  (rq - obsr == obsc - cq ) )
        {
            dir_val[7] = min(dir_val[7],rq-obsr-1);
        }
    }
    ll sum = 0;

    for(int i=0; i<8; i++)
    {
      sum += dir_val[i];
    }
    cout<<sum<<endl;

    return 0;
}
