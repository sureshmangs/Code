Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as 
https://leetcode.com/problems/design-tinyurl and it returns a short URL such 
as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.

There is no restriction on how your encode/decode algorithm should work. 
You just need to ensure that a URL can be encoded to a tiny URL and the 
tiny URL can be decoded to the original URL.

Implement the Solution class:

Solution() Initializes the object of the system.
String encode(String longUrl) Returns a tiny URL for the given longUrl.
String decode(String shortUrl) Returns the original long URL for the given shortUrl. 
It is guaranteed that the given shortUrl was encoded by the same object.
 

Example 1:

Input: url = "https://leetcode.com/problems/design-tinyurl"
Output: "https://leetcode.com/problems/design-tinyurl"

Explanation:
Solution obj = new Solution();
string tiny = obj.encode(url); // returns the encoded tiny url.
string ans = obj.decode(tiny); // returns the original url after deconding it.
 

Constraints:

1 <= url.length <= 104
url is guranteed to be a valid URL.










class Solution {
public:
    unordered_map <string, string> decodeMap;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string baseUrl = "http://tinyurl.com/";
        time_t now = time(0);
        string shortUrl = baseUrl + to_string(now);
        decodeMap[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decodeMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));


/* Approach: Use increasing numbers as shortUrl code 
Problems with the approach:
Using increasing numbers as codes like that is simple but has some disadvantages, which the below solution fixes:

If I'm asked to encode the same long URL several times, it will get several entries. 
That wastes codes and memory.
People can find out how many URLs have already been encoded. 
Not sure I want them to know.
People might try to get special numbers by spamming me with repeated 
requests shortly before their desired number comes up.
Only using digits means the codes can grow unnecessarily large. 
Only offers a million codes with length 6 (or smaller). 
Using six digits or lower or upper case letters would 
offer (10+26*2)6 = 56,800,235,584 codes with length 6.
*/















// longToShort -> {longUrl, uniqueCode}, shortToLong -> {uniqueCode, longUrl}

class Solution {
public:
    unordered_map <string, string> longToShort, shortToLong;
    string alphaNumeric, baseUrl;
    
    Solution() {
        alphaNumeric = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        baseUrl = "http://www.tinyurl.com/";
        srand(time(0)); // seed for random generator for rand()
    } 
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (longToShort.find(longUrl) == longToShort.end()) {
            int sizeOfUniqueCode = 6; // create shortUrl code of length 6
            string uniqueCode = "";
            
            while (1) {
                uniqueCode = "";
                for (int i = 0; i < sizeOfUniqueCode; i++) {
                    uniqueCode += (alphaNumeric[rand() % 62]);
                }
                
                // check if short url doesn't exists
                if (shortToLong.find(uniqueCode) == shortToLong.end()) break;
            }
            
            longToShort[longUrl] = uniqueCode;
            shortToLong[uniqueCode] = longUrl;
            
            return baseUrl + uniqueCode;
            
        } else return baseUrl + longToShort[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        //get uniqueCode from Url
        string uniqueCode = shortUrl.substr(23);
        return shortToLong[uniqueCode];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));


/*
It's possible that a randomly generated code has already been generated before. 
In that case, another random code is generated instead. 
Repeat until we have a code that's not already in use. 
How long can this take? Well, even if we get up to using half of the code space, 
which is a whopping 626/2 = 28,400,117,792 entries, then each code has a 50% chance 
of not having appeared yet. So the expected/average number of attempts is 2, 
and for example only one in a billion URLs takes more than 30 attempts. 
And if we ever get to an even larger number of entries and this does become a problem, 
then we can just use length 7. We'd need to anyway, as we'd be running out of available codes.
*/
