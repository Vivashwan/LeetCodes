class Solution {
private:
    int func(int n, int steps, int val, int copy)
    {
        if(val>n || steps>n)
        {
            return INT_MAX;
        }

        if(val==n)
        {
            return steps;
        }

        return min(func(n, steps+1, val+copy, copy), func(n, steps+2, 2*val, val));
    }
public:
    int minSteps(int n) {
        if(n==1)
        {
            return 0;
        }

        

        return func(n, 1, 1, 1);
    }
};