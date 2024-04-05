class Solution {
public:
    int minSetSize(vector<int>& arr) {
          int n=*max_element(arr.begin(),arr.end());
           vector<int>vec(n+1,0);
           for(int i=0;i<arr.size();i++){
               vec[arr[i]]++;
           }
           sort(vec.begin(),vec.end(),greater<int>());
           int cnt=0;
           int sum=0;
           for(int i=0;i<vec.size();i++){
                sum+=vec[i];
                cnt++;
                if(sum>=arr.size()/2)
                break;
           }
           return cnt;
    }
};