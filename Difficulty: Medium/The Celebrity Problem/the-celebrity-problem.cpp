class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int candidate = 0;

        // Step 1: Find a potential celebrity
        for (int i = 1; i < n; i++) {
            if (mat[candidate][i] == 1) {
                candidate = i;  // candidate knows i, so candidate can't be celebrity
            }
        }

        // Step 2: Verify the candidate
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                // Celebrity shouldn't know anyone, and everyone should know celebrity
                if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                    return -1;
                }
            }
        }

        return candidate;
    }
};
