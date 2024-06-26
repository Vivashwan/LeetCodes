class Solution {
public:
    string arrangeWords(string text) {
        vector<pair<int, string>> beSorted;
        string res = "";
        for (int i = 0; i < text.size(); i++) {
            string word = "";
            while (isalpha(text[i])) {
                word += tolower(text[i]);
                i++;
            }
            beSorted.push_back({word.size(), word});
        }
        
        stable_sort(beSorted.begin(), beSorted.end(), [](const pair<int, string> &a, const pair<int, string> &b) {
            return (a.first < b.first);
        });
        
        for (pair<int, string> pair : beSorted) {
            res += pair.second + " ";
        }
        
        res.pop_back();
        res[0] = toupper(res[0]);
        return res;
    }
};