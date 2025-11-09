class Solution {
private:
    int maxim=INT_MIN;

    int checkSimilar(vector<int>&a, vector<int>&b)
    {
        int count=0; 
        for(int i=0; i<a.size(); i++) 
        { 
            if(a[i]==b[i]) 
            { 
                count++; 
            }
        } 
        
        return count;
    }

    void func(vector<vector<int>>& students, vector<vector<int>>& mentors, vector<int>usedS, vector<int>usedM, int count, int n)
    {
        int i=-1;

        for(int x=0; x<n; x++)
        {
            if(usedS[x]==0)
            {
                i=x;
                break;
            }
        }

        if(i==-1)
        {
            maxim=max(maxim, count);
            return;
        }

        for(int j=0; j<n; j++)
        {
            if(usedM[j]==0)
            {
                count+=checkSimilar(students[i], mentors[j]);
                usedM[j]++;
                usedS[i]++;
                func(students, mentors, usedS, usedM, count, n);
                usedS[i]--;
                usedM[j]--;
                count-=checkSimilar(students[i], mentors[j]);
            }
        }
    }
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n=students.size();

        vector<int>usedS(n, 0), usedM(n, 0);

        func(students, mentors, usedS, usedM, 0, n);

        return maxim;
    }
};