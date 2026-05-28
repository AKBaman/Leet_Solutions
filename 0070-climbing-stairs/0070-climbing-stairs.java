class Solution {
    public int climbStairs(int n) {
        if(n<=2) return n;
        int prev2 = 1;
        int prev1 = 1;

        int curri = -1;
        for(int i=2;i<=n;i++){
            curri = prev1 + prev2;
            prev2 = prev1;
            prev1 = curri;
        }
        System.out.print(prev1 +" "+ prev2);
        return curri;
    }
}