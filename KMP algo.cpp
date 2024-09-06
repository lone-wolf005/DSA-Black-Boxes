class Solution {
public:
    int strStr(string a, string b) {
       if(a.size()< b.size())return -1;
       int m = b.size();

       b.push_back('#');
       b+=a;
       vector<int>lps(b.size(),0);
       int ans= -1;

       for(int i=1;i<lps.size();i++){
           int preInd = lps[i-1];
           
           while(preInd > 0 && b[i]!=b[preInd]){
                preInd = lps[preInd-1];
           }
           
           lps[i] = preInd + (b[i]==b[preInd]?1:0);   
       }
      
        
        
    }
};
