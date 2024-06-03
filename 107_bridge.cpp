    #include<bits/stdc++.h>
    void dfs(int i, vector<int>&dis, vector<int>&low,unordered_map<int,bool>&visited,unordered_map<int,vector<int>>&adj,int timer,
    vector<vector<int>>&result,int parent){
        visited[i]=1;
        int node = i;
        low[i]=timer;
        dis[i]=timer;
        timer++;
        
        for(auto nbr:adj[i]){
            if(nbr==parent)continue;
            if(!visited[nbr]){
                dfs(nbr,dis,low,visited,adj,timer,result,node);
                low[node]=min(low[node],low[nbr]);
                if(low[nbr]>dis[node]){
                    vector<int>ans;
                    ans.push_back(node);
                    ans.push_back(nbr);
                    result.push_back(ans);
                }
                    
                
                
            }
            else{
                low[node]=min(low[node],dis[nbr]);
            }
        }
    }
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
     unordered_map<int,vector<int>>adj;
     for(int i=0;i<edges.size();i++){
         int u = edges[i][0];
         int v = edges[i][1];
         adj[u].push_back(v);
         adj[v].push_back(u);
     }

        unordered_map<int,bool>visited;
        vector<int>dis(v);
        vector<int>low(v);
        int timer = 0;
        int parent = -1;
        vector<vector<int>>result;
        for(int i=0;i<v;i++){dis[i]=-1; low[i]=-1;}
        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfs(i,dis,low,visited,adj,timer,result,parent);
            }
        }
        return result;

}