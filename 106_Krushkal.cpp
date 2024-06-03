#include<bits/stdc++.h>
bool cmp(vector<int>a,vector<int>b){
	return a[2]<b[2];
}
void makeSet(vector<int>&parent,vector<int>&rank,int n){
	for(int i=0;i<=n;i++){
		rank[i]=0;
		parent[i]=i;
	}
}
int findParent(int node,vector<int>&parent){
	if(node==parent[node])return node;
	return parent[node]=findParent(parent[node],parent);
}
void unionset(int u,int v,vector<int>&parent,vector<int>&rank){
	u = findParent(u,parent);
	v = findParent(v,parent);

	if(rank[u]>rank[v]){
		parent[v]=u;
	}
	else if(rank[v]>rank[u]){
		parent[u]=v;
	}
	else{ parent[v]=u;
		  rank[u]++;
		}
}
int kruskalMST(int n, vector<vector<int>> &edges)
{  
	sort(edges.begin(),edges.end(),cmp);
	vector<int>parent(n+1);
	vector<int>rank(n+1);
	makeSet(parent,rank,n);
    int ans = 0;
	for(int i=0;i<edges.size();i++){
        int u = findParent(edges[i][0],parent);
		int v = findParent(edges[i][1],parent);
		int w = edges[i][2];
		if(v!=u){
			unionset(u,v,parent,rank);
            //want graph then add edges
			ans+=w;
		}
	}
	return ans;


}
