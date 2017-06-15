#include <bits/stdc++.h>
#define pb push_back
#define mpp make_pair
#define PI acos(-1)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int > pii;
const ll inf = 1e9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const ll MAX = 1e7 + 20;

int n;
vector< pii > edge;
vector< int > V[100005];
int col[100005];
set< int > colours;
set< int > :: iterator it;

int dfs( int node, int par )
{
    colours.insert( col[node] );

    for( int i  = 0; i < V[node].size(); i++ )
    {
        int x = V[node][i];

        if( x != par )
        {
            dfs( x, node );
        }
    }
}

bool solve( int root )
{
    for( int i  = 0; i < V[root].size(); i++ )
    {
        colours.clear();

        int x = V[root][i];

        dfs( x, root );

        if( colours.size() != 1 )
        {
            return false;
        }
    }

    return true;
}

int main ( )
{

#ifdef swapnil
    freopen("in.txt","r",stdin );
    //freopen("out.txt","w",stdout );
#endif // swapnil

    int n;
    cin >> n;

    for( int i = 2; i <= n; i++ )
    {
        int u, v;
        cin >> u >> v;

        V[u].pb( v );
        V[v].pb( u );

        edge.pb( mpp( u, v ) );
    }
    for( int i = 1; i <= n; i++ )
        cin >> col[i];

    for( int i = 0; i < edge.size(); i++ )
    {
        int a = edge[i].first;

        int b = edge[i].second;

        if( col[a] != col[b] )
        {
            int root = a;

            if( solve( a ) )
            {
                cout << "YES\n";
                cout << a << "\n";

                return 0;
            }
            if( solve( b ) )
            {
                cout << "YES\n";
                cout << b << "\n";

                return 0;
            }
            cout << "NO\n";

            return 0;
        }
    }
    cout << "YES\n";
    cout << 1 << "\n";

    return 0;
}
