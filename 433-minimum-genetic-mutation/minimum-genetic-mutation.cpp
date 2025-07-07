class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> set(bank.begin(),bank.end());
        string geneChar  = "ACGT";
        queue<pair<string,int>> q;
        q.push({startGene,0});

        while(!q.empty()){

            auto Gene = q.front().first;
            auto steps = q.front().second;
            q.pop();

            if(Gene == endGene) return steps;

            for(int i=Gene.size()-1;i>=0;i--){
                char original = Gene[i];
                for(int j=0;j<4;j++){
                    Gene[i]=geneChar[j];
                    if(set.find(Gene)!=set.end()){
                        q.push({Gene,steps+1});
                        set.erase(Gene);
                    }
                }
                Gene[i] = original;
            } 
        }

        return -1;
    }
};