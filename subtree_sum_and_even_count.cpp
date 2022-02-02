#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll N = 1e5+10;
vector<ll> g[N];

vector<ll> subtree(N), cnt_even(N);

void dfs(int vertex, int par = 0){

    if(vertex % 2 == 0){
        cnt_even[vertex]++;
    }
    subtree[vertex] += vertex;
    
    for(auto child: g[vertex]){

        if(child == par)    continue;
        
        dfs(child, vertex);
        subtree[vertex] += subtree[child];
        cnt_even[vertex] += cnt_even[child];
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

    for(int i=1;i<=n;i++){
        cout<<subtree[i]<<" "<<cnt_even[i]<<endl;
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