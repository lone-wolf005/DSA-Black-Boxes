class TrieNode{
    private:
      int data;
    public:
      TrieNode*children[2];
    TrieNode(int data){
        this->data = data;
        for(int i=0;i<2;i++){
            children[i] = NULL;
        }
    }
};
class Trie{
    private:
        TrieNode*root;
    
    public:
        Trie(){
           root = new TrieNode(-1);
        }
    
    void insertNumber(int num){
        TrieNode*node = root;

        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->children[bit]==NULL){
                node->children[bit] = new TrieNode(bit);
            }
            node = node->children[bit];
        }
    }
    int maxXor(int num){
         int ans = 0;

        TrieNode*node = root;

        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            bit = !bit;
            if(node->children[bit]){
                ans|=(1<<i);
                node = node->children[bit];
            }
            else node = node->children[!bit];
        }
        return ans;
    }
};
