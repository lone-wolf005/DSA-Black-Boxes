//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,stack<int>&topoSort){
	    vis[node] = 1;
	    for(auto x:adj[node]){
	        if(!vis[x]){
	            dfs(x,vis,adj,topoSort);
	        }
	    }
	    topoSort.push(node);
	}
	void dfs2(int node,vector<int>transposeGraph[],vector<int>&visited){
	    visited[node] = 1;
	    for(auto x:transposeGraph[node]){
	        if(!visited[x]){
	            dfs2(x,transposeGraph,visited);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int>topoSort;
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,topoSort);
            }
        }
        
        vector<int>transposeGraph[V];
        
        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                transposeGraph[x].push_back(i);
            }
        }
       
        int ans = 0;
        vector<int>vis2(V,0);
        while(!topoSort.empty()){
            int node =topoSort.top();
            topoSort.pop();
            if(!vis2[node]){
                ans++;
                dfs2(node,transposeGraph,vis2);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
