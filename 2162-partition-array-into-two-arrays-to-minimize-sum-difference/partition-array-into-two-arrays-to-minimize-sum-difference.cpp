class Solution {
public:

    void generate(vector<int>& arr, int idx, int cnt, int sum,
                  vector<vector<int>>& v) {

        if (idx == arr.size()) {
            v[cnt].push_back(sum);
            return;
        }

        // Take current element
        generate(arr, idx + 1, cnt + 1,
                 sum + arr[idx], v);

        // Skip current element
        generate(arr, idx + 1, cnt,
                 sum, v);
    }

    int minimumDifference(vector<int>& nums) {

        int n = nums.size();
        int half = n / 2;

        int total = 0;

        for (int x : nums)
            total += x;

        // Split into two halves
        vector<int> left(nums.begin(),
                         nums.begin() + half);

        vector<int> right(nums.begin() + half,
                          nums.end());

        vector<vector<int>> leftSums(half + 1);
        vector<vector<int>> rightSums(half + 1);

        // Generate all possible sums
        generate(left, 0, 0, 0, leftSums);
        generate(right, 0, 0, 0, rightSums);

        // Sort right side
        for (int i = 0; i <= half; i++) {
            sort(rightSums[i].begin(),
                 rightSums[i].end());
        }

        int ans = INT_MAX;

        // Take i elements from left
        // Take half-i elements from right
        for (int i = 0; i <= half; i++) {

            int j = half - i;

            for (int leftSum : leftSums[i]) {

                // We want:
                // leftSum + rightSum ≈ total / 2

                int target = total / 2 - leftSum;

                auto it = lower_bound(
                    rightSums[j].begin(),
                    rightSums[j].end(),
                    target
                );

                // Candidate 1
                if (it != rightSums[j].end()) {

                    int selectedSum =
                        leftSum + *it;

                    ans = min(
                        ans,
                        abs(total - 2 * selectedSum)
                    );
                }

                // Candidate 2
                if (it != rightSums[j].begin()) {

                    --it;

                    int selectedSum =
                        leftSum + *it;

                    ans = min(
                        ans,
                        abs(total - 2 * selectedSum)
                    );
                }
            }
        }

        return ans;
    }
};