class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;        // count of unmatched '('
        int insertions = 0;  // count of unmatched ')'

        for (char ch : s) {
            if (ch == '(') {
                open++;
            } else { // ch == ')'
                if (open > 0) {
                    open--; // match it with an open '('
                } else {
                    insertions++; // no '(' to match, need to insert one
                }
            }
        }

        // Total insertions needed = unmatched '(' + unmatched ')'
        return open + insertions;
    }
};
