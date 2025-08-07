class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<pair<int,pair<int,int>>> robot(n);

        for(int i=0;i<n;i++){
           healths[i] = (directions[i] == 'R') ? healths[i] : -healths[i];
           robot[i] = {positions[i],{healths[i],i}};
        }

        sort(robot.begin(),robot.end());

        // for(auto it : robot){
        //     cout<<it.first<<":"<<it.second.first<<":"<<it.second.second<<" ";
        // }

        vector<pair<int,int>> st;
        for(auto it: robot){
            int pos = it.first;
            int health = it.second.first;
            int index = it.second.second;

            while(!st.empty() && health< 0 && st.back().second > 0){
                int sum = st.back().second + health;

                if(sum < 0){
                    st.pop_back();
                    health = health+1;
                }
                else if(sum == 0){
                    st.pop_back();
                    health = 0;
                }
                else{
                    health=0;
                    st.back().second = st.back().second-1;
                }
            }
            if(health !=0 ){
                st.push_back({index,health});
            }
        }
        vector<int> ans;
        sort(st.begin(),st.end());
        for(auto it: st){
            cout<<it.first<<":"<<it.second<<" ";
            ans.push_back(abs(it.second));
        }
        
        return ans;
    }

};