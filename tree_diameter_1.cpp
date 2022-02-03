#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
const int N = 2e5+10;
vector<pair<int,int>> g[N];

vector<int> d(N),dis(N),dis1(N);

void dfs(int vertex, int par = 0){

    for(auto child: g[vertex]){
        if(child.first == par)    continue;

        d[child.first] = d[vertex] + child.second;

        dfs(child.first, vertex); 
    } 
}

void dfs1(int vertex, int par = 0){
    for(auto child: g[vertex]){
        if(child.first == par)    continue;

        dis[child.first] = dis[vertex] + child.second;

        dfs1(child.first, vertex);
    }
}
void dfs2(int vertex, int par = 0){
    for(auto child: g[vertex]){
        if(child.first == par)    continue;

        dis1[child.first] = dis1[vertex] + child.second;
        dfs2(child.first, vertex);
    }
}

void solve()
{
    int n;
    cin>>n;

    for(int i=0;i<n-1;i++){
        int v,e,d=1;
        cin>>v>>e;
        g[v].push_back({e,d});
        g[e].push_back({v,d});
    }

    dfs(1);
    int max_d = -1;
    int max_node1;

    for(int i=1;i<=n;i++){
        if(max_d < d[i]){
            max_d = d[i];
            max_node1 = i;
        }
        d[i] = 0;
    }

    dfs(max_node1);
    max_d = -1;

    int max_node2;

    for(int i=1;i<=n;i++){
        if(max_d < d[i]){
            max_d = d[i];
            max_node2 = i;
        }
        d[i] = 0;
    }

    // cout<<max_node1<<" "<<max_node2<<endl;

    dfs1(max_node1);
    dfs2(max_node2);

    for(int i=1;i<=n;i++){
        cout<<max(dis[i],dis1[i])<<" ";
    }
    cout<<endl;
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

        for(int i=0;i<N;i++){
            g[i].clear();
            d[i] = 0;
            dis[i] = 0;
            dis1[i] = 0;
        }
        

        #ifndef ONLINE_JUDGE
            cout << "---------------------------- " << endl;
        #endif
    }
    return 0;
}