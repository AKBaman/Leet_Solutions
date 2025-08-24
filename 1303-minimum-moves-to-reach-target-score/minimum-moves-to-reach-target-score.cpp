class Solution {
public:
    int findMoves(int target,int maxDoubles){
        int moves = 0;
        while(target > 1 && maxDoubles > 0){
            if(target%2 == 0){
                target/=2;
                maxDoubles--;
            }
            else{
                target-=1;
            }
            moves++;
        }
        moves +=(target-1);
        return moves;
    }
    int minMoves(int target, int maxDoubles) {
        int start=1,res=1;
        int moves = findMoves(target,maxDoubles);
        return moves;
    }

};