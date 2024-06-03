//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void dfs(int i,unordered_map<int,bool>&visited,stack<int>&st,vector<int>adj[]){
	    visited[i]=1;
	    for(auto x:adj[i]){
	        if(!visited[x]){
	            dfs(x,visited,st,adj);
	        }
	    }
	    st.push(i);
	}

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    // using dfs
// 	    stack<int>st;

// 	    unordered_map<int,bool>visited;
// 	    for(int i=0;i<V;i++){
// 	        if(!visited[i]){
// 	            dfs(i,visited,st,adj);
// 	        }
// 	    }
// 	    vector<int>ans;
// 	    while(!st.empty()){
// 	       int t = st.top();
// 	        ans.push_back(t);
// 	        st.pop();
// 	    }

// 	    return ans;
// 	}

    // USING KANS ALGORITHMS
    
    vector<int>ans;
    
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto y:adj[i]){
            indegree[y]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int f = q.front();
        ans.push_back(f);
        q.pop();
        for(auto x:adj[f]){
            indegree[x]--;
            if(!indegree[x])q.push(x);
        }
    }
    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends