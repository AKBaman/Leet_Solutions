class Solution {
public:
    int Winner(vector<bool>& person,int n,int  k,int index,int person_left){
        if(person_left==1){
            for(int i=0;i<n;i++){
                if(person[i]==0){
                    return i+1;
                }
            }
        }

        int kill = (k-1)%person_left;

        while(kill--){
            index = (index+1)%n;
            while(person[index]==1){
                index = (index+1)%n;
            }
        }
        person[index]=1;

        while(person[index]==1){
            index = (index+1)%n;
        }

        return Winner(person,n,k,index,person_left-1);
    }
    int findTheWinner(int n, int k) {
        //Array for keeping the check which person has been killed already;
        vector<bool>person(n,0);
        int person_left = n;
        int index=0;
        return Winner(person,n,k,index,person_left);
    }
};