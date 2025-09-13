class Solution {
private:
    char dir[4]={'A', 'C', 'G', 'T'};
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene==endGene)
        {
            return 0;
        }

        unordered_set<string>bankLookUp(bank.begin(), bank.end());

        unordered_set<string>visited;

        visited.insert(startGene);

        queue<string>q;
        q.push(startGene);

        int count=0;

        while(!q.empty())
        {
            int size=q.size();

            for(int i=0; i<size; i++)
            {
                string gene=q.front();
                q.pop();

                if(gene==endGene)
                {
                    return count;
                }

                for(int j=0; j<gene.size(); j++)
                {
                    char original=gene[j];
                    
                    for(int d=0; d<4; d++)
                    {
                        gene[j]=dir[d];

                        if(bankLookUp.find(gene)!=bankLookUp.end())
                        {   
                            if(visited.find(gene)==visited.end())
                            {
                                visited.insert(gene);
                                q.push(gene);
                            }
                        }
                    }

                    gene[j]=original;
                }
            }

            count++;
        }

        return -1;
    }
};