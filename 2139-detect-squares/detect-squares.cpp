class DetectSquares {
private:
    map<pair<int, int>, int>mp;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int count=0;
        int x = point[0], y = point[1];

        for(auto it: mp)
        {
            pair<int, int>u = it.first;

            if(u.first!=x && u.second!=y && (abs(u.first-x)==abs(u.second-y)))
            {
                int f1 = mp[{u.first, u.second}],
                f2 = mp[{u.first, y}],
                f3 = mp[{x, u.second}];

                count+=f1*f2*f3;
            }
        }

        return count;
    }
};