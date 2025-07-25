/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<NestedInteger>st;

    void makeTopAnInteger()
    {
        while(!st.empty())
        {
            NestedInteger it=st.top();

            if(it.isInteger())
            {
                return;
            }

            st.pop();

            vector<NestedInteger>&adj=it.getList();

            for(int i=adj.size()-1; i>=0; i--)
            {
                st.push(adj[i]);
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=nestedList.size()-1; i>=0; i--)
        {
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        makeTopAnInteger();

        int val=st.top().getInteger();
        st.pop();

        return val;
    }
    
    bool hasNext() {
        makeTopAnInteger();

        return !st.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */