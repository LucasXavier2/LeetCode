//Description of the problem - https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        
        if(x < 10 && x > -10) return x;
        
        long reversed_number = 0;
        long multiplier = 1;
        vector<int> digits;
        
        while(x != 0) {
            digits.push_back(x % 10);
            x /= 10;   
        }
        
        for(int i = digits.size()-1; i >= 0; i--){
            reversed_number += digits[i] * multiplier;
            multiplier *= 10;
        }
        
        //Check for overflows and underflows
        if(reversed_number > pow(2, 31) -1 || reversed_number < -pow(2, 31)) return 0;
        return reversed_number;
    }
};