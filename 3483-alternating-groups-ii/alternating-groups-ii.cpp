class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        //modified array for circular array
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }

        int n = colors.size();
        int count = 0;
        int i=0,j=1;
        while(j<n){
            if(colors[j-1]!=colors[j]){
                if(j-i+1 == k){
                    count++;
                    i++;
                }
            }
            else{
                i=j;
            }
            j++;
        }

        return count;


    }
};