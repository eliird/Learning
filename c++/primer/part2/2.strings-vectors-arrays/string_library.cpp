#include <iostream>
#include <string>
#include <limits>
#include <sstream>

using std::cin; 
using std::cout; 
using::std::endl;
using std::string; 


void exercise1(){
    //types of initialization
    string s5 = "hiya"; //copy iinitialization
    string s6("hiya"); // direct initialization
    string s7(10, 'c'); //direct initialization
    
    /*
    code belw is equivalent to 
    string temp(10, 'c');
    string s8 = temp;
    */
    string s8 = string(10, 'c'); //copy initialization



}

void excercise2(){
    /*
    reading and writing strings

    Some useful functions for strings
    - s.emptyy() returns true if string is empty
    - s.size() return the number of chars in s
        - it might be common to assume it returns int but it returns string::size_type
        - so when reading it try to use auto or explicitly use string::size_type instead of ints
        - also be careful when comparing it with ints e.g in case of n < 0 word.size() < n would always yield true
    - s[n] returns the character at position n
    - s1 + s2 concatanates the string
    - s1 = s2 replace characters in s1 with copy of s2
    - s1 == s2 returns true if they contain the same characters
    - s1 != s2 inequality is case sensitive
    - <, <=, >, >= comparision are case sensitive and use dictionary ordering
    */
   // reading a word from istream
   string t1 = "hello";
   string t2 = "hello world";
   cout << (t2 == t1) << " " << (t1 == t2) << endl;
   string s;
   cin >> s;
   cout << "you entered: " << s <<endl;

   //flush stream
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   //reading a line from input streamn
   string s2;
   getline(cin, s2);
   cout << "you entered: " << s2 <<endl;

}


void excercise3(){
    /*
    reading unknown number of strings from stream
    */
   string word;
   while (cin >> word)
        cout << word << endl;

}

void excercise4(){
    /*
    reading complete line of string
    */
   string line;
   while (getline(cin, line))
        if (!line.empty())
            cout << line << endl;

}


void excercise5(){
    /*
    read a line of string and write words in the line
    */
   string line;
   while(getline(cin, line)){
    string word;    
    std::stringstream ss(line);
        while (ss >> word)
            cout << word << endl;
   }
}

bool excercise6(const string &a, const string &b){
    /*
    program to checkj if two strings are equal or not
    */
   return a == b;
}

void excercise7(){
    /*
    looping over characters in string

    some usefule char level functions
    - isalnum(c) true if c is a letter or figit
    - isalpha(c) truce if c is alphabetic
    - iscntrl(c) true if c is control char
    - isdigit(c), isxdigit(c) // x for hexa
    - isgraph(c) true if c is not space but is printable
    - islower(), isupper()
    - isprint()
    - ispunct()
    - isspace()
    - tolower(),     - toupper()


    */
    string a = "hello, darkness my old friend.";
    for (auto c: a)
        // cout <<c << endl;
        continue;

    //counting punctuations
    unsigned int punc_cnt;
    for (auto c: a)
        if (ispunct(c))
            punc_cnt++;
    cout << a << endl;
    cout << punc_cnt << " punctuations in the sentnce " << endl;


    // process characters in s until we run out of characters or we hit a whitespace
    string s = "some string";
    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
        s[index] = toupper(s[index]); // capitalize the current character
    cout << s << endl;

    for(char &c: s)
        if (!isspace(c))
            c = 'x';
    cout << s << endl;
    char temp;
    string::size_type n = 0;
    while (n < s.size())
    {
        temp = s[n];
        if (!isspace(temp))
            s[n] = 'u';
        n++;
    }   
    cout << s << endl;

}

int main(){

    excercise7();
}