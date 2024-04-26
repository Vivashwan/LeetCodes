class Solution {
public:
    int numSteps(string s) {
        int count = 0;

        while(s!="1")
        {
            if(s.back()=='0')
            {
                count++;
                s.pop_back();
            }
            else
            {
                while(!s.empty() and s.back()=='1')
                {
                    count++;
                    s.pop_back();
                }

                if(s.empty())
                {
                    // s = "1";
                    count++;
                    return count;
                }

                s.back()='1';

                count++;
            }
        }

        return count;
    }
};