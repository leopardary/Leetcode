/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        const char *p1=s;
        int count=0;
        int count1=0;
        while(*p1!='\0'){   //before the pointer arrives at the end.
            if (*p1==' ') {
                
                count1=count;   //record the length of the last word.
                
                while(*(p1+1)==' ') p1++;   //if there are multiple spaces, jump through them, until the next element is a word.
                if(*(p1+1)!='\0') count=0;  //only if the next element is not end of the string, the count need to be reset.
                
            }
            else {count++;  //if current element is not a space, count ++
                
            }
            
            if (*(p1+1)=='\0'){ 
                count1=count;
            }
            p1++;
        }
        
        return count1;
    }
};