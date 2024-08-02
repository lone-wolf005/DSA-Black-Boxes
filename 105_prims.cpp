//Radhe Radhe
#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
#define ll long long int
int Factorial[500000+10];
class Node{
    // private:
    public:
    int wt,node,parent;
    Node(int wt,int node,int parent){
        this->wt = wt;
        this->node = node;
        this->parent = parent;
    }
};

int prims(int src,int n,vector<pair<int,int>>adj[],vector<vector<int>>&mst){
    
    priority_queue<Node*,vector<Node*>,greater<Node*>>pq;
    pq.push(new Node(0,0,-1));
    vector<int>visited(n,0);
    int sum = 0;

    while(!pq.empty()){
         auto tp = pq.top();
         pq.pop();
         int wt = tp->wt;
         int node = tp->node;
         int parent = tp->parent;
         if(!visited[node]){
             visited[node] = 1;
             sum+=wt;
             if(parent !=-1){
                mst.push_back({node,parent});
             }
         }
         for(auto x:adj[node]){
             if(!visited[x.first]){
                  pq.push(new Node(x.second,x.first,node));
             }
         }

    }
    return sum;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<m;i++){
        int a,b,wt;
        cin>>a>>b>>wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }
    vector<vector<int>>mst;
    int sum = prims(0,n,adj,mst);
    cout<<sum<<endl;
    for(auto x:mst){
        cout<<x[0]<<" "<<x[1]<<endl;
    }
    
return 0;
}
