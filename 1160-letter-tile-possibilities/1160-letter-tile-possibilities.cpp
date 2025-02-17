class Solution {
public:
    int numTilePossibilities(string tiles) {
        set<string> set;

        sort(tiles.begin(),tiles.end());

        do{
            for(int i=1;i<=tiles.size();i++){
                set.insert(tiles.substr(0,i));
            }
        }while(next_permutation(tiles.begin(),tiles.end()));

        return set.size();
    }
};