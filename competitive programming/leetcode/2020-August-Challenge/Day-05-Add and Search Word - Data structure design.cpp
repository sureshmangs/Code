Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

   Hide Hint #1
You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.













class WordDictionary {
public:

    struct TrieNode {
        bool ew;  // end of word
        struct TrieNode* child[26];   // a-z
    };

    struct TrieNode* root;   // define root

    struct TrieNode* createNode(){
        struct TrieNode* newNode=new TrieNode;
        newNode->ew=false; // not end of word
        for(int i=0;i<26;i++)
            newNode->child[i]=NULL;
        return newNode;
    }

    void insert(struct TrieNode* root, string word){
        int n=word.length();
        struct TrieNode* curr=root;
        for(int i=0;i<n;i++){
            int index=word[i]-'a';
            if(curr->child[index]==NULL)
                curr->child[index]=createNode();
            curr=curr->child[index];
        }
        curr->ew=true;    // mark end of word
    }

    bool searchUtil(struct TrieNode* node, int i, string word){
        if(node==NULL) return false;
        if(i==word.length()) return node->ew;

        if(word[i]=='.'){
            for(int k=0;k<26;k++){
                if(searchUtil(node->child[k], i+1, word)) return true;
            }
        } else {
            int index=word[i]-'a';
            if(searchUtil(node->child[index], i+1, word)) return true;
        }
        return false;
    }

    /** Initialize your data structure here. */
    WordDictionary() {
        root=createNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        insert(root, word);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchUtil(root, 0, word);  // root, start index of word, word itself
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
