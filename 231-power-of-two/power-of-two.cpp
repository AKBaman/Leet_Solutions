class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) return false;
        double result = log10(n)/log10(2);

        return floor(result) == result;
    }
};