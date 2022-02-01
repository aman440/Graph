#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)

const ll N = 1e5;
vector<ll> g1[N];

vector<bool> vis(N, 0);

bool dfs(ll vertex){
    vis[vertex] = 1;

    for(auto child: g1[vertex]){
        if(vis[child]) continue;

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
    ll cnt = 0;
    rep(i,1,n+1){
        if(!vis[i]){
            cnt++;
            dfs(i);
        }
    }

    cout<<cnt<<endl;
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