# :rocket: CPP Notes
:pencil2: C++ Programming Notes

# :point_right: String Manipulation

### :white_check_mark: stoi()

```
The stoi() function takes a string as an argument and returns its value.
```

```
string str1 = "45";
string str2 = "3.14159";
string str3 = "31337 geek";

int myint1 = stoi(str1);  // 45
int myint2 = stoi(str2);  // 3
int myint3 = stoi(str3);  // 31337
```



### :white_check_mark: to_string()

```
This function accepts a number(can be any data type) and returns the number in the desired string.
```

```
int i_val = 20;
float f_val = 30.50;
string stri = to_string(i_val);  // 20
string strf = to_string(f_val);  // 30.500000
```



### :white_check_mark: stringstream

```
This is an easy way to convert strings of digits into ints, floats or doubles.
```

```
string s = "12345";
stringstream geek(s);
int x = 0;
geek >> x;
cout <<x;    // 12345
```


### :white_check_mark: char(digit) to int

```
In ASCII codes, the numbers (digits) start from 48
```

```
cout<<'1'-'0';  // 1
cout<<'1'-48;    // 1
cout<<char(1+'0');  // '1'
cout<<char(1+48);   // '1'
```

### :white_check_mark: uppercase and lowercase

```
ASCII  A is 65,  a is 97
```

```
cout<<char('a'-32); // 'A'
cout<<char('A'+32);  // 'a'
```


### :white_check_mark: substr()

```
This function takes two values pos and len as an argument and returns a newly constructed string object with its value initialized to a copy of a sub-string of this object.
```

```
string s1 = "Geeks";
string r = s1.substr(1, 3);
cout << "String is: " << r;   // String is: eek
```



### :white_check_mark: find()

```
find is used to find the first occurrence of sub-string in the specified string being called upon. It returns the index of the first occurrence of the substring in the string from given starting position. The default value of starting position is 0.

string::npos is a constant (probably -1) representing a non-position. It's returned by method find when the pattern was not found.
```

```
if(s.find(B)!=string::npos){
  cout<<"string found";
}
```


### :white_check_mark: append()

```
Extends the string by appending additional characters at the end of its current value
```

```
  string str;
  string str2="Writing ";
  string str3="print 10 and then 5 more";

  // used in the same order as described above:
  str.append(str2);                       // "Writing "
  str.append(str3,6,3);                   // "10 "
  str.append("dots are cool",5);          // "dots "
  str.append("here: ");                   // "here: "
  str.append(10,'.');                    // ".........."
  str.append(str3.begin()+8,str3.end());  // " and then 5 more"
  ```





### :white_check_mark: erase()
```
Erases a part of the string content, shortening the length of the string
```
```
string str = "abcdefgh";

// Deletes all characters
str.erase();                //  ""

// Deletes all characters after the given position element
str.erase(1);           //  "a"
str.erase(3);           //  "abc"
str.erase(0);            //  ""
str.erase(9);         // runtime error - terminate called after throwing an instance of 'std::out_of_range'

// Erases at most, len characters starting from the index poistion
str.erase(2, 3);        // "abfgh"


// Erase the single character at iterator position pos
str.erase(str.begin());        //   "bcdefgh"
str.erase(str.begin()+5);      //   "abcdegh"
str.erase(str.end()-1);         //   "abcdefg"

// Erase characters from iterator pos. to another iterator pos
// Erases all characters of the range [ beg, end)
str.erase(str.begin(), str.end());     //  ""
str.erase(str.begin()+2, str.end()+5);     // "abfgh"
str.erase(str.begin()+2, str.end()-2);     // "abgh"

```






# :point_right: Bit Manipulation

```
NOT ( ~ )  AND ( & )  OR ( | )  XOR ( ^ )  Left Shift ( << )  Right Shift ( >> )
```

```
N = 5 = (101)2
~N = ~5 = ~(101)2 = (010)2 = 2

A = 5 = (101)2 , B = 3 = (011)2 A & B = (101)2 & (011)2= (001)2 = 1

A = 5 = (101)2 , B = 3 = (011)2
A | B = (101)2 | (011)2 = (111)2 = 7

A = 5 = (101)2 , B = 3 = (011)2
A ^ B = (101)2 ^ (011)2 = (110)2 = 6

1 << 1 = 2 = 21
1 << 2 = 4 = 22 1 << 3 = 8 = 23
1 << 4 = 16 = 24

1 << n = 2n


4 >> 1 = 2
6 >> 1 = 3
5 >> 1 = 2
16 >> 4 = 1
```

```
Left shift operator is a binary operator which shift the some number of bits, in the given bit pattern, to the left and append 0 at the end.

Left shift is equivalent to multiplying the bit pattern with 2^k ( if we are shifting k bits )

Right shift operator is a binary operator which shift the some number of bits, in the given bit pattern, to the right and append 1 at the end.

Right shift is equivalent to dividing the bit pattern with 2k ( if we are shifting k bits ).
```


### :white_check_mark: Check if number is a power of 2

```
Properties for numbers which are powers of 2, is that they have one and only one bit set in their binary representation.

If the number is neither zero nor a power of two, it will have 1 in more than one place.

So if x is a power of 2 then x & (x-1) will be 0.
```

```
x = 4 = (100)2
x - 1 = 3 = (011)2
x & (x-1) = 4 & 3 = (100)2 & (011)2 = (000)2

x = 6 = (110)2
x - 1 = 5 = (101)2
x & (x-1) = 6 & 5 = (110)2 & (101)2 = (100)2

For a x, the binary representation of (x-1) can be obtained by simply flipping all the bits to the right of rightmost 1 in x and also including the rightmost 1.
```

```
bool isPowerOfTwo(int x){
        // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
        return (x && !(x & (x - 1)));
}
```

### :white_check_mark: Count ones in binary representation

```
int count_one (int n){
      while( n ){
           n = n & (n-1);
           count++;
       }
      return count;
}
```
```
Let, n = 5 , count = 0
n & (n-1) = 5 & 4 = 4  , count =1
n & (n-1) = 4 & 3 = 0  , count = 2

Complexity: O(K), where K is the number of ones present in the binary form of the given number.
```


### :white_check_mark: Check if the ith bit is set in the binary representation

```
Let number be N, and to check whether it’s ith bit is set or not, we can AND it with the number 2^i .
The binary form of 2^i contains only ith bit as set (or 1), else every bit is 0.

When we AND it with N, and if the ith bit of N is set, then it will return a non zero number (2^i to be specific), else 0 will be returned.

Using Left shift operator, we can write 2^i as 1 << i
```
```
bool check (int N){
    if( N & (1 << i) )
        return true;
    else
        return false;
}
```
```
Let, N = 5 = (101)2
To check its 2nd bit is set or not, i=2,   1 << 2 = (100)2
N & (1 << i ) = true
```


### :white_check_mark: Generate all possible subsets of a set

```
A = {a, b, c}

We need 3 bits, one bit for each element.
1 represent that the corresponding element is present in the subset.
0 represent the corresponding element is not in the subset.

0 = (000)2 = {}
1 = (001)2 = {c}
2 = (010)2 = {b}
3 = (011)2 = {b, c}
4 = (100)2 = {a}
5 = (101)2 = {a, c}
6 = (110)2 = {a, b}
7 = (111)2 = {a, b, c}
```
```
possibleSubsets(A, N):
        for i = 0 to 2^N:
            for j = 0 to N:
                if jth bit is set in i:
                    print A[j]
            print "\n"
```
```
void possibleSubsets(char A[], int N){
     for(int i = 0;i < (1 << N); ++i){
         for(int j = 0;j < N;++j)
             if(i & (1 << j))
                cout << A[j] << " ";
         cout << endl;
     }
}
```

### :white_check_mark: Largest power of 2 (MSB in binary form), which is less than or equal to the number

```
When all the bits of a number N are 1, then N must be equal to the 2^i -1 , where i is the number of bits in N.

N = 7 = 2^3 - 1, where 3 is the number of bits in N.
```
```
Let N = 16,      (1000000000000000)2.

Changing all right side bits to 1

N = N | (N>>1)   (1100000000000000)2
N = N | (N>>2)   (1111000000000000)2
N = N | (N>>4)   (1111111100000000)2
N = N | (N>>8)   (1111111111111111)2

Now the number is 2 * x-1, where x is required answer, so adding 1 and dividing it by 2

N = (N+1)>>1
```
```
long largest_power(long N){
     N = N| (N>>1);
     N = N| (N>>2);
     N = N| (N>>4);
     N = N| (N>>8);

     return (N+1)>>1;
}
```

```
Let number be N, we find the number of bits - 1 in the binary representation of the number.
Then the 2^(number of bits - 1) is our result.
```
```
int MSB(int n){
    int k = (int)(log2(n));
    return (int)(pow(2, k));
}
```

```
Note:

x ^ ( x & (x-1)) : Returns the rightmost 1 in binary representation of x

x = 10 = (1010)2 ` x & (x-1) = (1010)2 & (1001)2 = (1000)2
x ^ (x & (x-1)) = (1010)2 ^ (1000)2 = (0010)2



x & (-x) : Returns the rightmost 1 in binary representation of x

x = 10 = (1010)2
(-x) = -10 = (0110)2
x & (-x) = (1010)2 & (0110)2 = (0010)2



x | (1 << n) : Returns the number x with the nth bit set

x = 10 = (1010)2 n = 2
1 << n = (0100)2
x | (1 << n) = (1010)2 | (0100)2 = (1110)2
```

### :white_check_mark: One's complement

```
Inverting every bit of N
One's complement of N is ~N
Let N = 4, ~N = -5
```
```
For complement till number of bits in num

int findComplement(int num) {
        int bits = floor(log2(num))+1;
        long long tmp = (long long )(1 << bits)-1;       // pow(2, bits) == ( 1 << bits )
        int res = num^tmp;
        return res;
    }
```
```
Let, N = 22 = (10110)2
One's complement of 22 is 9  (01001)2
Count of bits in binary representation of 22 is 5. Let, c = 5
So we need c times 1, that is  11111.
To get this ,we left shift 1 c times and subtract 1 from it.
On left shifting one c times we get 100000, on subtracting 1 we get 11111
Now we perform XOR with N (10110) and the calculated value (11111), we get our desired result
```

### :white_check_mark: Two's complement

```
Two's complement = One's complement + 1
Two's complement of N is -N
Two's complement of N is (~N + 1)
Let N = 4,  -N = -4,  (~N + 1) = -4
```

### :white_check_mark: XOR from 1 to N

```
Find the remainder of N with 4
If remainder = 0, then xor will be  N
If remainder = 1, then xor will be 1
If remainder = 2, then xor will be N+1
If remainder = 3,then xor will be 0

Number Binary  XOR-from-1-to-N
1         1           [0001]   --> 1
2        10           [0011]   --> N+1
3        11           [0000]   --> 0
4       100           [0100]   --> N
5       101           [0001]   --> 1
6       110           [0111]   --> N+1
7       111           [0000]   --> 0
8      1000           [1000]   --> N
9      1001           [0001]   --> 1
10     1010           [1011]   --> N+1
11     1011           [0000]   --> 0
12     1100           [1100]   --> N
```

### :white_check_mark: Swap 2 numbers

```
Let the numbers be a and b
a ^= b;
b ^= a;
a ^= b;
```

### :white_check_mark: Check if bits are in alternate pattern

```
Calculate num = N ^ (N >> 1).
If N has an alternate pattern, then N ^ (N >> 1) will produce a number having set bits only.
```
```
bool hasAlternatingBits(int n) {
        if(n==0) return true;
        int bits = floor(log2(n)) + 1;
        int tmp = pow(2, bits) - 1;
        return (n ^ (n >> 1)) == tmp ? true : false;
    }
```




### :white_check_mark: ASCII

```
'A' ---> 65       'Z' ---> 90
'a' ---> 97       'z' ---> 122
'0' ---> 48       '9' ---> 57
(space) ---> 32



Commonly used tables are:

int[26] for Letters 'a' - 'z' or 'A' - 'Z'
int[128] for ASCII
int[256] for Extended ASCII
```



# :point_right: Array/Vector

### :white_check_mark: memset()

```
This function copies a single character for a specified number of time to an object.
We can use memset() to set all values as 0 or -1 for integral data types also.
It will not work if we use it to set as other values.
The reason is simple, memset works byte by byte.
```

```
char str[] = "hello";
memset(str, 'a', sizeof(str));  // str ->  aaaaaa

int A[5];
memset(A, 0, sizeof(A));  // all elements of A are 0
memset(A, -1, sizeof(A));  // all elements of A are -1
memset(A, 5, sizeof(A)); // WRONG, all elements of A will be set to Garbage Values
```

### :white_check_mark: fill()
```
This function assigns the value ‘val’ to all the elements in the range [begin, end)
```

```
int arr[10];
fill(arr, arr + 10, 4);   // arr ->  4 4 4 4 4 4 4 4 4 4

vector<int> vect(8);
fill(vect.begin() + 2, vect.end() - 1, 4); // vect ->  0 0 4 4 4 4 4 0
```



:white_check_mark: fill_n()

```
A vector, once declared, has all its values initialized to zero.
vector<int> v(8);  // v -> 0 0 0 0 0 0 0 0

To initialize the vector with some specific value
vector<int> v(8, 1);  // v -> 1 1 1 1 1 1 1 1


vector<int> v(8);
fill(v.begin() + 2, v.end() - 1, 4); // v -> 0 0 4 4 4 4 4 0
```
```
In fill_n(), we specify beginning position, number of elements to be filled and values to be filled.
```
```
vector<int> v(8);
fill_n(v.begin(), 4, 7);  // v ->  7 7 7 7 0 0 0 0
fill_n(v.begin() + 3, 3, 4);  v -> 7 7 7 4 4 4 0 0
```



# :point_right: Number Generate

### :white_check_mark: rand()

```
Returns a pseudo-random integral number in the range between [0, RAND_MAX).
This number is generated by an algorithm that returns a sequence of apparently non-related numbers each time it is called.
This algorithm uses a seed to generate the series, which should be initialized to some distinctive value using function srand().

If random numbers are generated with rand() without first calling srand(), your program will create the same sequence of numbers each time it runs.

RAND_MAX: is a constant whose default value may vary between implementations but it is granted to be at least 32767.
```
```
v1 = rand() % 100;         // v1 in the range 0 to 99
v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
v3 = rand() % 51 + 50;   // v3 in the range 50 to 100

Notice though that this modulo operation does not generate uniformly distributed random numbers in the span (since in most cases this operation makes lower numbers slightly more likely).
```

### :white_check_mark: srand()

```
The srand() function sets the starting point for producing a series of pseudo-random integers.
If srand() is not called, the rand() seed is set as if srand(1) were called at program start.
Any other value for seed sets the generator to a different starting point.

srand(unsigned seed_value); // setting seed value to seed_value

Standard practice is to use the result of a call to srand(time(0)) as the seed.
time() returns a time_t value which vary everytime and hence the pseudo-random number vary for every program call.

In short, srand() —> Set Seed for rand() Function.

Why can't we use time(0) instead of random and srand()
Because time(0) returns the time in seconds.
If you're generating a lot of random numbers in each second, you'll end up with the same numbers in each second.
```




## References

- [Basics of Bit Manipulation: HackerEarth](https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/tutorial/)
- [Bits manipulation: GeeksForGeeks](https://www.geeksforgeeks.org/bits-manipulation-important-tactics/)
- [Append: Cplusplus](http://www.cplusplus.com/reference/string/string/append/)
- [MSB: GeeksforGeeks](https://www.geeksforgeeks.org/find-significant-set-bit-number/)
