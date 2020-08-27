//Description of the problem - https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (needle.size() > haystack.size()) return -1;
        
        for (int i = 0; i < haystack.size(); i++) {
            if (i + needle.size() > haystack.size()) break;
            
            if (haystack[i] == needle[0]) {
                int matches = 1;
                for (int m = 1; m < needle.size(); m++) {
                    if (haystack[i+m] == needle[m]) {
                        matches++;
                    }
                }
                if (matches == needle.size()) return i;
            }
        }
        
        return -1;
    }
};



//Solution using std::string::compare (http://www.cplusplus.com/reference/string/string/compare/)

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (needle.size() > haystack.size()) return -1;
        
        for (int i = 0; i < haystack.size(); i++) {
            if (i + needle.size() > haystack.size()) break;
            if (haystack.compare(i, needle.size(), needle) == 0) return i;
        }
        
        return -1;
    }
};