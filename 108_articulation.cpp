//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
  void dfs(int node,int parent,vector<bool>&ans,vector<int>&dis,vector<int>&low,
  unordered_map<int,bool>&visited,vector<int>adj[],int &timer){
      visited[node]=1;
      dis[node]=low[node]=timer++;
      int child = 0;
      for(auto x:adj[node]){
          if(x==parent)continue;
          if(!visited[x]){
              dfs(x,node,ans,dis,low,visited,adj,timer);
              low[node]=min(low[x],low[node]);
              if(low[x]>=dis[node] && parent !=-1){
                  ans[node]=1;
                  
              }
              child++;
          }
          else{
              low[node]=min(low[node],dis[x]);
          }
          
      }
      if(parent == -1 && child>1){
          ans[node]=1;
      }
  }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        
        vector<bool>ans(V,false);
        
        vector<int>dis(V);
       
        
        vector<int>low(V);
        for(int i=0;i<V;i++){
            dis[i]=-1;
            low[i]=-1;
        }
        unordered_map<int,bool>visited;
        int timer = 0;
        dfs(0,-1,ans,dis,low,visited,adj,timer);
        vector<int>result;
        // for(auto x:ans)cout<<x<<" ";
        for(int i=0;i<V;i++){
            if(ans[i])result.push_back(i);
        }
        if(result.size()==0)result.push_back(-1);
        return result;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends