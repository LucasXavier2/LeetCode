//Description of the problem - https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        
        if(x < 10 && x > -10) return x;
        
        long reversed_number = 0;
        
        while(x != 0) {
            int digit = x % 10;
            reversed_number = reversed_number * 10 + digit;
            x /= 10;   
        }

        if(reversed_number > pow(2, 31) -1 || reversed_number < -pow(2, 31)) return 0;
        return reversed_number;
        
    }
};