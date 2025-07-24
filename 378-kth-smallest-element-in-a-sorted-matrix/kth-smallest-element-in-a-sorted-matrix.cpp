class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxH; //maxHeap;

        for(vector<int> it : matrix){
            for(int num : it){
                maxH.push(num);
                if(maxH.size() > k) maxH.pop();
            }
        }

        return maxH.top();
    }
};