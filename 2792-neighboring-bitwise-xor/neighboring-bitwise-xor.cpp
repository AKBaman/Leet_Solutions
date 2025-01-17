class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int temp=0;
        for(int n : derived){
            temp^=n;
        }
        return temp==0;
    }
};