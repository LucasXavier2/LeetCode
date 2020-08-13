//Description of the problem - https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> checking;
        int stringLength = s.size();
        
        for(int i = 0; i < stringLength; i++){
            char currentChar = s[i];
            
            if(currentChar == '(' || currentChar == '{' || currentChar == '[') {
                checking.push(currentChar);
            }
            else if (checking.empty()) {
                return false;
            }
            else if(currentChar == ')') {
                if (checking.top() != '(') return false;
                checking.pop();
            } 
            else if(currentChar == '}') {
                if (checking.top() != '{') return false;
                checking.pop();
            } 
            else if(currentChar == ']') {
                if (checking.top() != '[') return false;
                checking.pop();
            }
        }
        
        if(checking.empty()) return true;
        return false;
    }
};