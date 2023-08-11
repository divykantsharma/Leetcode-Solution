class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char data){
        this->data=data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        this->isTerminal=false;
    }
};
class Trie{
public:
    TrieNode* root;
    Trie(){
        root=new TrieNode(' ');
    }
    void insert(string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        TrieNode* curr=root;
        for(int i=0;i<word.length();i++){
            if(!curr->children[word[i]-'a']){
                curr->children[word[i]-'a']=new TrieNode(word[i]);
            }
            curr=curr->children[word[i]-'a'];
        }
        curr->isTerminal=true;
    }
    bool search(string word){
        TrieNode* curr=root;
        for(int i=0;i<word.size();i++){
            if(curr->children[word[i]-'a']){
                curr=curr->children[word[i]-'a'];
            }
            else return false;
        }
        return curr->isTerminal;
    }
    bool startsWith(string prefix){
        TrieNode* curr=root;
        for(int i=0;i<prefix.size();i++){
            if(curr->children[prefix[i]-'a']){
                curr=curr->children[prefix[i]-'a'];
            }
            else return false;
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