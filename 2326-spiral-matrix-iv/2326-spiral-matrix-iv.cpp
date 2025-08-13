/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>res(m, vector<int>(n, -1));

        int dir[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int direc=0;
        int x=0, y=0;

        for(ListNode* curr=head; curr; curr=curr->next)
        {
            res[x][y]=curr->val;

            int nx=x+dir[direc][0], ny=y+dir[direc][1];

            if(nx<0 || nx>=m || ny>=n || ny<0 || res[nx][ny]!=-1)
            {
                direc=(direc+1)%4;
                nx=x+dir[direc][0];
                ny=y+dir[direc][1];
            }

            x=nx, y=ny;
        }

        return res;
    }
};