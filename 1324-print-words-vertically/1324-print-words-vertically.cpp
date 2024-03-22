class Solution {
public:
    vector<string> printVertically(string s) {
    vector<string> words;
    s += ' ';
    string temp;
    for (auto it : s) {
      if (it == ' ') {
        words.push_back(temp);
        temp.clear();
      }
      else temp += it;
    }

    // Step2
    int maxWordLength=0;
    for (auto it : words) {
      int currentWordLength = it.size();
      maxWordLength = max(maxWordLength, currentWordLength);
    }
    
    //Step3
    vector<string> ans;
    for (int j = 0; j < maxWordLength; j++) {
      string temp;
      for (int i = 0; i < words.size(); i++) {
        if (j < words[i].size())  temp += words[i][j];
        else temp += ' ';
      }
      while (temp.back() == ' ') temp.pop_back();
      ans.push_back(temp);
      temp.clear();
    }
    return ans;
  }
};