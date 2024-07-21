class Solution {
private:
    int solve(int ind, string& s, unordered_set<string>& st, string temp){
        if(ind == s.length())
            return 0;
        else{
            temp.push_back(s[ind]);
            int op1 = -1;
            int op2 = -1;
			// if new substring is not present in the set
            if(st.find(temp) == st.end()){
                st.insert(temp);
                op1 = 1 + solve(ind+1, s, st, "");  //since new substring is added we increase the cnt by 1 and create a new substring to check from very next index -----> in other words we pick that string
                st.erase(temp);
            }
			// picked part was done,  its time for not picking the char at that index and moving to the next one
            op2 = solve(ind+1, s, st, temp);
            return max(op1, op2);
        }
    }
public:
    int maxUniqueSplit(string s) {
        // creating unordered_set to keep track which substring is visited
        unordered_set<string> st;
		// recursion function
        return solve(0, s, st, ""); 
    }
};