/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false
*/
/*
Note for converting string to const char *:
If you just want to pass a std::string to a function that needs const char* you can use

std::string str;
const char * c = str.c_str();
If you want to get a writable copy, like char *, you can do that with this:

std::string str;
char * writable = new char[str.size() + 1];
std::copy(str.begin(), str.end(), writable);
writable[str.size()] = '\0'; // don't forget the terminating 0

// don't forget to free the string after finished using it
delete[] writable;
*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        const char *star=NULL;
        const char *ss=s;
        while(*s!='\0'){
            if(*s==*p || *p=='?') {s++;p++;continue;}
            if(*p=='*') {star=p++;ss=s;continue;}
            if(star) {p=star+1;s=++ss;continue;}
            return false;
        }
        while(*p=='*') p++;
        if(*p=='\0') return true;
		else return false;
    }
};
int main(){
	string a="aa";
	string b="*";
	const char *a1=a.c_str();
	const char *b1=b.c_str();
	Solution calculate;
	cout<<calculate.isMatch(a1,b1);
	return 0;
}