class Solution {
public:
    bool check(string str,int num,int indx,int currentSum){
        if(currentSum > num){
            return false;
        }
        if(currentSum == num && indx==str.size()){
            return true;
        }
        for(int j=indx;j<str.size();j++){
            string s = str.substr(indx,j-indx+1);
            if(stoi(s) > num) break;
            if(check(str,num,j+1,currentSum + stoi(s))){
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int result=0;
        for(int num=1;num<=n;num++){
            int sq = num*num;
            string str = to_string(sq);
            if(check(str,num,0,0)){
                result+=sq;
            }
        }
        return result;
    }
};