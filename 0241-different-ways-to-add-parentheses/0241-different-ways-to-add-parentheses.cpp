class Solution {
private:
    vector<int>func(string expression)
    {
        vector<int>res;

        for(int i=0; i<expression.size(); i++)
        {
            char ch=expression[i];

            if(ch=='*' || ch=='-' || ch=='+')
            {
                vector<int>left=func(expression.substr(0, i));
                vector<int>right=func(expression.substr(i+1));

                for(auto l: left)
                {
                    for(auto r: right)
                    {
                        if(ch=='*')
                        {
                            res.push_back(l*r);
                        }
                        else if(ch=='-')
                        {
                            res.push_back(l-r);
                        }
                        else if(ch=='+')
                        {
                            res.push_back(l+r);
                        }
                    }
                }
            }
        }

        if(res.empty())
        {
            res.push_back(stoi(expression));
        }

        return res;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        return func(expression);
    }
};