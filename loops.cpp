#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)

const ll N = 1e5;
vector<ll> g1[N];
bool isv = 0;
vector<bool> vis(N, 0);

void dfs(ll vertex, ll par){
    vis[vertex] = 1;

    for(auto child: g1[vertex]){
        if(vis[child] && child == par) continue;
        if(vis[child])  isv = 1;  // if child is already visited and it is not parent so loop exist
        dfs(child, vertex);
        
    }

}

void solve()
{
    ll n,e;
    cin>>n>>e;
    // n is number of vertex
    // e is number of edges


    rep(i,0,e){
        ll v,u;
        cin>>v>>u;

        g1[v].pb(u);
        g1[u].pb(v);
    }
    bool ok = 0;
    rep(i,1,n+1){
        if(!vis[i]){
            dfs(i,0);
            if(isv){
                break;
            }
        }
    }

    if(isv){
        cout<<"Yes Loop Exist"<<endl;
    }
    else{
        cout<<"Loop Does Not Exist"<<endl;
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