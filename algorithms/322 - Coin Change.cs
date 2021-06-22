//Description of the problem - https://leetcode.com/problems/coin-change/

public class Solution {
    public int CoinChange(int[] coins, int amount) {
            int[] partialSolutions = new int[amount + 1];
            partialSolutions[0] = 0;
        
            for (int i = 1; i <= amount; i++) {
                partialSolutions[i] = amount + 1;
                for (int j = 0; j < coins.Length; j++) {
                    if (coins[j] <= i) {
                        partialSolutions[i] = Math.Min(partialSolutions[i], 1 + partialSolutions[i - coins[j]]);
                    }
                }
            }

            return partialSolutions[amount] > amount ? -1 : partialSolutions[amount];
    }
}