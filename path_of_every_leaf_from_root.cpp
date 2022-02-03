#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)

const int N = 1e5+10;
vector<int> g[N];
vector<int> cat(N); 

int ans = 0;

vector<int> no;

void dfs(int vertex, int par){
    bool ok = 1;
    no.push_back(vertex);

    for(auto child: g[vertex]){
        if(child == par)    continue;
        ok = 0;

        dfs(child, vertex);

    }

    if(ok){
        for(auto x:no){
            cout<<x<<" ";
        }
        cout<<endl;
        // no.clear();
    }
    no.pop_back();
    
}

void solve()
{
    int n,m;
    cin>>n>>m;

    rep(i,1,n+1)    cin>>cat[i];

    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;

        g[x].push_back(y);
        g[y].push_back(x);
    }    

    dfs(1,0);
    cout<<ans<<endl;

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