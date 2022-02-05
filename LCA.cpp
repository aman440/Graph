#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)

const ll N = 3e5+10;
vector<ll> g[N];

vector<ll> p(N);

vector<ll> ans;
vector<ll> res;

void dfs(ll vertex, ll par){
    p[vertex] = par;
    
    for(auto child: g[vertex]){
        if(child == par)    continue;

        dfs(child,vertex);
    }
}

vector<ll> path(int v){
    vector<ll> pt;

    while(v != -1){
        pt.pb(v);
        v = p[v];
    }
    reverse(pt.begin(),pt.end());
    return pt;
}

void solve()
{

    ll n;
    cin>>n;


    for(int i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1,-1);

    int v1,v2;
    cin>>v1>>v2;

    vector<ll> pt1 = path(v1);
    vector<ll> pt2 = path(v2);

    int min_size = min(pt1.size(),pt2.size());
    ll lca;

    for(int i=0;i<min_size;i++){
        if(pt1[i] == pt2[i]){
            lca = pt1[i];
        }
    }

    cout<<lca<<endl;



    
#ifndef ONLINE_JUDGE
    cout << "---------------------------- " << endl;
#endif
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
    }
    return 0;
}