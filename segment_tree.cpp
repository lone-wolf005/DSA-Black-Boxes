#include <bits/stdc++.h>
using namespace std;
class SGTree{
    public:
    vector<int>seg;
     SGTree(int n){
        seg.resize(4*n + 1);
     }

     void build(int ind,int low,int high,vector<int>&arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
     }
     int query(int ind,int low,int high,int l,int r){
        if(r<low || l > high){
            return INT_MAX;
        }
        else if(low >=l && high <=r){
            return seg[ind];
        }
        else{
            int mid = (low + high)/ 2;
            int left = query(2*ind+1,low,mid,l,r);
            int right = query(2*ind+2,mid+1,high,l,r);
            return min(left,right);
        }
     }
     void update(int ind,int low,int high,int i,int value){
        if(low == high){
            seg[ind] = value;
            return ;
        }
        int mid = (low + high ) / 2;
        if(i<=mid){
            update( 2*ind + 1,low,mid,i,value);
        }
        else{
            update(2*ind + 2,mid+1,high,i,value);
        }
        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
     }

};
int main(){
    SGTree sg1(5);
    vector<int>arr={1,2,3,4,5};
    sg1.build(0,0,4,arr);
    cout<<sg1.query(0,0,4,2,4)<<endl;

    // point update
    // 1 - index
    // value = 5
    sg1.update(0,0,4,1,5);
    arr[1]=5;
    cout<<sg1.query(0,0,4,1,1)<<endl;

    
    
}