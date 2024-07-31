	//Function to return list containing vertices in Topological order.
	void dfs(int node,vector<int>&visited,vector<int>adj[],stack<int>&st){
	    visited[node] = 1;
	    for(auto x:adj[node]){
	        if(!visited[x])dfs(x,visited,adj,st);
	    }
	    st.push(node);
	}
