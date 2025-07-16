class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int n=pushed.size();
        int j=0;
        int i=0;
        while(i<n && pushed[i]!=popped[j]){
            s.push(pushed[i]);
            i++;
        }
        if(i==n){
            return false;
        }
        s.push(pushed[i]);
        i++;
        while(j<n){
            while(!s.empty()&&s.top()==popped[j]){
                s.pop();
                j++;
            }
            if(i<n){
                s.push(pushed[i]);
                i++;
            }else{
                if(!s.empty()&&s.top()!=popped[j]){
                    return false;
                }
            }
        }
        return true;
    }
};