/*
Trie is an efficient information retrieval data structure. Use this data structure to store Strings and search strings. Your task is to use the TRIE data structure and search the given string A. If found print 1 else 0.

Expected Time Complexity: O(N * WORD_LEN + A_LEN).
Expected Auxiliary Space: O(N * WORD_LEN).

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of three lines.
First line of each test case consist of a integer N, denoting the number of element in a Trie to be stored.
Second line of each test case consists of N space separated strings denoting the elements to be stored in the trie.
Third line of each test case consists of a String A to be searched in the stored elements.

Output:
Print the respective output in the respective line.

Constraints:
1<=T<=20
1<=N<=20

Example:
Input:
1
8
the a there answer any by bye their
the
Output:
1
*/









#include<bits/stdc++.h>
using namespace std;

#define ALP_SIZE 26

struct TrieNode {
    bool ew;   // end of word
    struct TrieNode* child[ALP_SIZE];
};

struct TrieNode* createNode(){
    struct TrieNode* newNode=new TrieNode;
    newNode->ew=false;
    for(int i=0;i<ALP_SIZE;i++)
        newNode->child[i]=NULL;
    return newNode;
}

void insert(struct TrieNode* root, string word){
    struct TrieNode* cur=root;
    int wordLen=word.length();
    for(int i=0;i<wordLen;i++){
        int index=word[i]-'a';
        // create new node if not already exist
        if(cur->child[index]==NULL)
            cur->child[index]=createNode();
        // point to new node
        cur=cur->child[index];
    }
    cur->ew=true; // end of word
}

bool search(struct TrieNode* root, string item){
    struct TrieNode* cur= root;
    int itemLen=item.size();
    for(int i=0;i<itemLen;i++){
        int index=item[i]-'a';
        if(cur->child[index]==NULL) return false;
        cur=cur->child[index];
    }
    return (cur!=NULL && cur->ew);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> words;
        for(int i=0;i<n;i++){
            string ch;
            cin>>ch;
            words.push_back(ch);
        }
        struct TrieNode* root= createNode();

        for(int i=0;i<n;i++)
            insert(root, words[i]);

        string item;
        cin>>item;
        cout<<search(root, item)<<endl;
    }
return 0;
}
