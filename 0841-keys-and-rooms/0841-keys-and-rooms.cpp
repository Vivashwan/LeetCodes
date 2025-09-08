class Solution {
private:
    void func(vector<vector<int>>&rooms, int room, vector<bool>&visited)
    {
        if(visited[room]==true)
        {
            return;
        }

        visited[room]=true;

        for(auto it: rooms[room])
        {
            func(rooms, it, visited);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();

        vector<bool>visited(n, false);

        visited[0]=true;

        for(auto it: rooms[0])
        {
            func(rooms, it, visited);
        }


        for(auto it: visited)
        {
            if(it==false)
            {
                return false;
            }
        }

        return true;
    }
};