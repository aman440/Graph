#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)

const ll N = 1e5;
vector<ll> g1[N];

vector<bool> vis(N, 0);

void dfs(ll vertex){

    // if(vis[vertex]) return;
    vis[vertex] = 1;

    for(auto child: g1[vertex]){

        cout<<"par "<<vertex<<"child "<<child<<endl;

        if(vis[child])  continue;

        cout<<child<<endl;

        dfs(child);
    }
}

void solve()
{
    ll n;
    cin>>n;

    rep(i,0,n){
        ll v,u;
        cin>>v>>u;

        g1[v].pb(u);
        g1[u].pb(v);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        #ifndef ONLINE_JUDGE
            cout << "---------------------------- " << endl;
        #endif
    }
    return 0;
}