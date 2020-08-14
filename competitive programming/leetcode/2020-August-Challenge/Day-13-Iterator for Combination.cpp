Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.


Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false


Constraints:

1 <= combinationLength <= characters.length <= 15
There will be at most 10^4 function calls per test.
It's guaranteed that all calls of the function next are valid.
   Hide Hint #1
Generate all combinations as a preprocessing.
   Hide Hint #2
Use bit masking to generate all the combinations.












class CombinationIterator {
public:
    queue<string> q;

    void allCombinations(string characters, int k, int s, string str){
        if(k==0){
            q.push(str);
            return;
        }
        for(int i=s; i<characters.length();i++){
            str+=characters[i];
            allCombinations(characters, k-1, i+1, str);
            str.erase(str.end()-1);
        }
    }

    CombinationIterator(string characters, int combinationLength) {
        string str="";
        allCombinations(characters, combinationLength, 0, str);  // <characters, combinationLength, start, str>
    }

    string next() {
        string next =  q.front();
        q.pop();
        return next;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
