class SGT
{
    public:
    vector<ll>seg;
    int n;

    SGT(int n){
        seg.resize(4*n+1);
        this->n = n;
    }
    void build(int ind,int low,int high,vector<ll>&arr){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }
        ll mid = (low+high)/2;
        build(2*ind,low,mid,arr);
        build(2*ind+1,mid+1,high,arr);
        merge(ind);
    }
    ll query(int ind,int low,int high,int l,int r){
        if(r<low || l>high){
            return LLONG_MAX;
        }
        if(low>=l && high<=r){
            return seg[ind];
        }
        else{
            ll mid = (low + high)/2;
            ll left = query(2*ind,low,mid,l,r);
            ll right = query(2*ind+1,mid+1,high,l,r);
            // return left + right;
            return merge2(left,right);
        }
    }
    void update(int ind,int low,int high,int i,int value){
          if(low==high){
            seg[ind] = value;
            return;
        }
        ll mid = (low+high)/2;
        if(i<=mid){
            update(2*ind,low,mid,i,value);
        }
        else update(2*ind+1,mid+1,high,i,value);
        merge(ind);  
    }
    void merge(int ind){
        //  seg[ind] = seg[2*ind]+seg[2*ind+1];
         seg[ind] =min(seg[2*ind],seg[2*ind+1]);
    }
    ll merge2(ll a,ll b){
        return min(a,b);
    }
    void buildUtil(vector<ll>&arr){
         build(1,0,n-1,arr);
    }
    void updateUtil(int ind,int val){
        update(1,0,n-1,ind,val);
        // for(auto x:seg)cout<<x<<" ";
    }
    ll queryUtil(int l,int r){
       return query(1,0,n-1,l,r);
    }


};
