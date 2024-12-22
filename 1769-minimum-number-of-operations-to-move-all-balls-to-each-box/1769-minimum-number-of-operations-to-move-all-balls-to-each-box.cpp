class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> left(boxes.size(), 0), right(boxes.size(), 0), ans(boxes.size(), 0);
        int balls = 0;
        
        balls = boxes[0] - '0';
        for(int i=1;i<boxes.size();i++){
            left[i] = left[i-1] + balls;
            balls += boxes[i] - '0';
        }
        
        balls = boxes[boxes.size()-1] - '0';
        for(int i=boxes.size()-2;i>=0;i--){
            right[i] = right[i+1] + balls;
            balls += boxes[i] - '0';
        }
        
        for(int i=0;i<boxes.size();i++)
            ans[i] = left[i] + right[i];
        
        return ans;
    }
};