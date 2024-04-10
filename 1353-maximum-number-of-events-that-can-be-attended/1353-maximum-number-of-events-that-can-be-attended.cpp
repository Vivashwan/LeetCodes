class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
         sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]); // Sort events based on end time, if end times are equal, then sort based on start time
        });

        int count = 0;
        vector<bool> attended(events.back()[1] + 1, false); // Keep track of attended events using a boolean array

        for (const auto& event : events) {
            for (int i = event[0]; i <= event[1]; ++i) {
                if (!attended[i]) {
                    attended[i] = true;
                    ++count;
                    break;
                }
            }
        }

        return count;
    }
};