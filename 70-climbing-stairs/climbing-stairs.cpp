class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        vector<int> pos(46,0);
        pos[0] = 1;
        pos[1] = 1;
        for(int i=2;i<=n;i++){
            pos[i] = pos[i-1] + pos[i-2];
        }
        return pos[n-1] + pos[n-2];
    }
};