class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        // Maps lake ID → the last day it was filled with rain
        unordered_map<int, int>lastRained;

        // Stores the indices (days) where dry days occurred
        set<int>availableDryDays;

        // Final result array, initialized to 1 (dry any lake arbitrarily)
        vector<int>result(n, 1);

        for (int day = 0; day < n; day++) {
            int lake = rains[day];

            if (lake == 0) {
                // It's a dry day — store this day index
                availableDryDays.insert(day);
                // Initially assume we're drying lake 1 (will be updated if needed)
                result[day] = 1;
            } else {
                // It's raining on a lake
                result[day] = -1;

                if (lastRained.find(lake) != lastRained.end()) {
                    // This lake has already been filled before and not yet dried
                    int lastRainDay = lastRained[lake];

                    // Find the next available dry day after the last time it rained on this lake
                    auto dryDayIt = availableDryDays.upper_bound(lastRainDay);
                    if (dryDayIt == availableDryDays.end()) {
                        // No dry day found to prevent flooding
                        return {};
                    }

                    // Use that dry day to dry this lake
                    result[*dryDayIt] = lake;
                    availableDryDays.erase(dryDayIt);
                }

                // Update the latest rain day for this lake
                lastRained[lake] = day;
            }
        }

        return result;
    }
};
