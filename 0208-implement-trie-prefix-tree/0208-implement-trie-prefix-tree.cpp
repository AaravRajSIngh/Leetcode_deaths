class TrieNode{
    public:
    TrieNode* child[26];
    bool isEnd;
    TrieNode()
    {
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
        isEnd=false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();        
    }
    void insert(string word) {
        TrieNode* node=root;
        for(char c:word)
        {
            int idx=c-'a';
            if(node->child[idx]==nullptr)
            {
                node->child[idx]=new TrieNode();
            }
            node=node->child[idx];
        }    
        node->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* node=root;
        for(char c:word)
        {
            int idx=c-'a';
            if(node->child[idx]==nullptr)
                return false;
            node=node->child[idx];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(char c:prefix)
        {
            int idx=c-'a';
            if(node->child[idx]==nullptr)
            {
                return false;
            }
            node=node->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */