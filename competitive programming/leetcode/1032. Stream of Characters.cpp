Implement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.


Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist


Note:

1 <= words.length <= 2000
1 <= words[i].length <= 2000
Words will only consist of lowercase English letters.
Queries will only consist of lowercase English letters.
The number of queries is at most 40000.







    struct TrieNode {
            bool ew; // end of word
            struct TrieNode* child[26];
    };

    struct TrieNode* createNode(){
        struct TrieNode* newNode=new TrieNode;
        newNode->ew=false;
        for(int i=0;i<26;i++)
            newNode->child[i]=NULL;
        return newNode;
    }

    void insert(struct TrieNode* root, string word){
            struct TrieNode* cur=root;
            int wordLen=word.length();
            for(int i=wordLen-1;i>=0;i--){
                int index=word[i]-'a';
                // create new node if not already exist
                if(cur->child[index]==NULL)
                    cur->child[index]=createNode();
                // point to new node
                cur=cur->child[index];
            }
            cur->ew=true; // end of word
      }



class StreamChecker {
public:
    struct TrieNode* root= createNode();
    string stream="";


    StreamChecker(vector<string>& words) {

        int n=words.size();
        for(int i=0;i<n;i++)
            insert(root, words[i]);

    }

    bool query(char letter) {
        stream+=letter;
        TrieNode* cur=root;
        int sLen=stream.length();
        for(int i=sLen-1; i>=0;i--){
            int index=stream[i]-'a';
            if(cur->ew==true) return true;
            if(cur->child[index]==NULL) return false;
            cur=cur->child[index];
        }
        return (cur!=NULL && cur->ew);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
