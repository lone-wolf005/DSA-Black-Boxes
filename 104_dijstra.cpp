//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        // unordered_map<int,bool>visited;
        
        vector<int>dist(V);
        for(int i=0;i<V;i++)dist[i]=INT_MAX;
        set<pair<int,int>>st;
        st.insert({0,S});
        dist[S]=0;
        
        while(!st.empty()){
            auto top = *(st.begin());
            int node = top.second;
            int di = top.first;
            st.erase(top);
            
            for(auto x:adj[node]){
                // cout<<x[0]<<" ";
                if(di + x[1] < dist[x[0]]){
                    auto record = st.find({dist[x[0]],x[0]});
                    if(record !=st.end())st.erase(record);
                    dist[x[0]] = di + x[1];
                    
                    st.insert({dist[x[0]],x[0]});
                }
            }
        }
        return dist;
     
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends