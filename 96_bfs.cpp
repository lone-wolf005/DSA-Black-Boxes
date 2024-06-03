//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(vector<int> adj[],unordered_map<int,bool>&visited,int i,vector<int>&ans){
        queue<int>q;
        visited[i]=1;
        ans.push_back(i);
        q.push(i);
       
        while(!q.empty()){

             int front = q.front();
             q.pop();
            for(int j=0;j<adj[front].size();j++){
                int ele = adj[front][j];
                if(!visited[ele]){
                      q.push(ele);
                      visited[ele]=1;
                      ans.push_back(ele);
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        // Code here
        // unordered_map<int,vector<int>>list;
        // for(int i=0;i<V;i++){
        //     for(int j=0;j<adj[i].size();j++){
        //         list[i].push_back(adj[i][j]);
        //     }
        // }
        // for(auto x:list){
        //     cout<<x.first<<endl;
        //     for(auto y:x.second)cout<<y;
        //     cout<<endl;
        // }
        unordered_map<int,bool>visited;
        vector<int>ans;
        
        // for(int i=0;i<V;i++){
        //     if(!visited[i]){
                bfs(adj,visited,0,ans);
        //     }
        // }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends