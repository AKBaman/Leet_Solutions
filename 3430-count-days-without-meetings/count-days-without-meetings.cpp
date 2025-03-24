class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int start = 0;
        int end = 0;
        int count=0;
        for(int i=0;i<meetings.size();i++){
            int nstart = meetings[i][0];
            if(nstart > end){
                count+=(nstart-end-1);
            }
            end = max( meetings[i][1],end);
        }
        if(days > end){
            count+=(days-end);
        }

        return count;
    }
};