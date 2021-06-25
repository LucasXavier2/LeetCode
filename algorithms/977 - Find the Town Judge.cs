//Description of the problem - https://leetcode.com/problems/find-the-town-judge/

public class Solution {
    public int FindJudge(int n, int[][] trust) {   
        int[] people = new int[n + 1];
        
        for (int i = 0; i < trust.Length; i++) {
            people[trust[i][0]]--;
            people[trust[i][1]]++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (people[i] == n-1) {
                return i;
            }
        }
        
        return -1;
    }
}