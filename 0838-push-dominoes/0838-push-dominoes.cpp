class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();

        int force=0;

        vector<int>forces(n, 0);

        for(int i=0; i<n; i++)
        {
            if(dominoes[i]=='R')
            {
                force=n;
            }
            else if(dominoes[i]=='L')
            {
                force=0;
            }
            else force=max(0, force-1);

            forces[i]+=force;
        }

        for(int i=n-1; i>=0; i--)
        {
            if(dominoes[i]=='L')
            {
                force=n;
            }
            else if(dominoes[i]=='R')
            {
                force=0;
            }
            else force=max(0, force-1);

            forces[i]-=force;
        }

        string res="";

        for(int i=0; i<n; i++)
        {
            if(forces[i]>0)
            {
                res+='R';
            }
            else if(forces[i]<0)
            {
                res+='L';
            }
            else res+='.';
        }

        return res;
    }
};