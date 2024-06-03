#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,vector<pair<int,int>>>adj;
    for(auto x:g){
        int u = x.first.first;
        int v = x.first.second;
        int w = x.second;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<bool>mst(n+1);
    vector<int>parent(n+1);
    vector<int>key(n+1);
    for(int i=0;i<=n;i++)key[i]=INT_MAX;
    key[1]=0;
    // parent[0]

    for(int i=1;i<=n;i++){
        int u;
        int mini = INT_MAX;
        for(int j=1;j<=n;j++){
            if(!mst[j]&&key[j]<mini){
                mini=key[j];
                u=j;
            }
        }
        mst[u]=1;
        for(auto x:adj[u]){
            int v = x.first;
            int w = x.second;
            if(!mst[v] && w < key[v]){
                key[v]=w;
                parent[v]=u;
            }
        } 
    }
    vector<pair<pair<int, int>, int>>ans;
    for(int i=2;i<=n;i++){
        ans.push_back({{i,parent[i]},key[i]});
    }
return ans;
}


// o(nlogn)


// #include <bits/stdc++.h> 
// vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
// {
//     unordered_map<int,vector<pair<int,int>>>adj;
//     for(auto x:g){
//         int u = x.first.first;
//         int v = x.first.second;
//         int w = x.second;
//         adj[u].push_back({v,w});
//         adj[v].push_back({u,w});
//     }
//     vector<bool>mst(n+1);
//     vector<int>parent(n+1);
//     vector<int>key(n+1);
//     for(int i=0;i<=n;i++)key[i]=INT_MAX;
//     key[1]=0;
//     // parent[0]
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
//     q.push({0,1});

//     while(!q.empty()){
//         auto fr = q.top();
//         q.pop();
//         int u = fr.second;
//         if(mst[u])continue;
//         mst[u]=1;
//         for(auto x:adj[u]){
//             int v = x.first;
//             int w = x.second;
//             if(!mst[v] && w < key[v]){
//                 key[v]=w;
//                 parent[v]=u;
//                 q.push({w,v});
//             }
//         } 
//     }
//     vector<pair<pair<int, int>, int>>ans;
//     for(int i=2;i<=n;i++){
//         ans.push_back({{i,parent[i]},key[i]});
//     }
// return ans;
// }
