#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll N = 1e5;
vector<ll> g[N];

vector<int> d(N),h(N);

void dfs(int node, int par = 0){
    for(auto child : g[node]){
        if(child == par)    continue;

        d[child] = d[node] + 1;

        dfs(child, node);

        h[node] = max(h[node], h[child]+1);
    }
}

void solve()
{
    int n;
    cin>>n;

    for(int i=0;i<n-1;i++){
        int v,e;
        cin>>v>>e;
        g[v].push_back(e);
        g[e].push_back(v);
    }

    dfs(1);

    rep(i,1,n+1){
        cout<<d[i]<<"--"<<h[i]<<endl;
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