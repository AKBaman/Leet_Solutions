class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1) return false;
        double res = log10(n)/log10(4);
        return floor(res) == res;
    }
};