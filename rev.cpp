
/*⠀⠀⠀⠀
 Moon, tell me if I could
Send up my heart to you?
So, when I die, which I must do
Could it shine down here with you?
… 'Cause my love is mine, all mine
I love mine, mine, mine
Nothing in the world belongs to me
But my love, mine, all mine, all mine
… My baby here on Earth
Showed me what my heart was worth
So, when it comes to be my turn
Could you shine it down here for her?
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
#define ln     "\n";
#define all(v) v.begin(), v.end()
#define Fast_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
int LCsubstring(string a, string b) {
    int n = a.size(), m = b.size(), res = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                res = max(res, dp[i][j]);
            }
        }
    }
    return res;
}
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            int left = target - nums[i];
            if(mp.count(left) && mp[left] != i) {
                return {i, mp[left]};
            }
        }
        return {};
    }
};

class Solution {
  public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

class Solution {
  public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for(int num : nums) {
            if(count == 0) candidate = num;
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};

class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string s = "";
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs.back();
        for(int i = 0; i < min(first.size(), last.size()); i++) {
            if(first[i] != last[i]) return s;
            s += first[i];
        }
        return s;
    }
};

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        int l = 1e18;
        int maxi = 0;
        for(int price : prices) {
            l = min(l, price);
            maxi = max(maxi, price - l);
        }
        return maxi;
    }
};

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return unique(nums.begin(), nums.end()) != nums.end();
    }
};

class Solution {
  public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] > target) h = mid - 1;
            if(nums[mid] < target) l = mid + 1;
        }
        return l;
    }
};

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

class Solution {
  public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            ans.push_back(ans[i - 1] + nums[i]);
        }
        return ans;
    }
};

class Solution {
  public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for(char c : s) {
            mp[c]++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(mp[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

class Solution {
  public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(nums[i]);
            ans.push_back(nums[n + i]);
        }
        return ans;
    }
};

class Solution {
  public:
    int arrangeCoins(int n) {
        int i = 1;
        while(i <= n) {
            n -= i;
            i++;
        }
        return i;
    }
};

class Solution {
  public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int left = 1, right = x, ans = 0;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(mid <= x / mid) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

class Solution {
  public:
    int addDigits(int num) {
        while(num > 9) {
            int temp = 0;
            while(num) {
                temp += num % 10;
                num /= 10;
            }
            num = temp;
        }
        return num;
    }
};

class Solution {
  public:
    int lengthOfLastWord(string s) {
        istringstream stream(s);
        string word;
        int k = 0;
        while(stream >> word) {
            k = word.size();
        }
        return k;
    }
};

class Solution {
  public:
    bool isMonotonic(vector<int>& nums) {
        return is_sorted(nums.begin(), nums.end()) || is_sorted(nums.rbegin(), nums.rend());
    }
};

class Solution {
  public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = 1;
        }
        int i = 0;
        while(i < nums.size()) {
            if(mp[i] != 1) {
                return i;
            }
            i++;
        }
        return nums.size();
    }
};

class Solution {
  public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if(stk.empty()) return false;
                char top = stk.top();
                if(c == ')' && top == '(' || c == '}' && top == '{' || c == ']' && top == '[') {
                    stk.pop();
                } else
                    return false;
            }
        }
        return stk.empty();
    }
};

class Solution {
  public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string doubled = s + s;
        return doubled.find(goal) != string::npos;
    }
};

class Solution {
  public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int maxi = INT_MIN;
        for(int i : nums) {
            ans = i ? ans + 1 : 0;
            maxi = max(maxi, ans);
        }
        return maxi;
    }
};

class Solution {
  public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin() + 1, nums.end());
        return nums[0] + nums[1] + nums[2];
    }
};

class Solution {
  public:
    bool isPalindrome(const string& s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while(l < r) {
            if(s[l] != s[r]) {
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
            l++;
            r--;
        }
        return true;
    }
};

class Solution {
  public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums);
        ans.insert(ans.end(), nums.begin(), nums.end());
        return ans;
    }
};

class Solution {
  public:
    bool isBalanced(TreeNode* root) {
        function<int(TreeNode*)> height = [&](TreeNode* node) -> int {
            if(!node) return 0;
            int lh = height(node->left);
            if(lh == -1) return -1;
            int rh = height(node->right);
            if(rh == -1) return -1;
            if(abs(lh - rh) > 1) return -1;
            return max(lh, rh) + 1;
        };
        return height(root) != -1;
    }
};

class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for(int i = 0; i < numRows; i++) {
            res[i].resize(i + 1);
            res[i][0] = res[i][i] = 1;
            for(int j = 1; j < i; j++) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
};

// Easy Done

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0, left = 0;
        for(int right = 0; right < s.size(); right++) {
            if(mp.count(s[right]) && mp[s[right]] >= left) {
                left = mp[s[right]] + 1;
            }
            mp[s[right]] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

class LRUCache {
  private:
    int capacity;
    unordered_map<int, int> cache;
    deque<int> order;

  public:
    LRUCache(int capacity) : capacity(capacity) {}
    int get(int key) {
        if(cache.find(key) == cache.end()) {
            return -1;
        }
        auto it = find(order.begin(), order.end(), key);
        order.erase(it);
        order.push_back(key);
        return cache[key];
    }

    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            auto it = find(order.begin(), order.end(), key);
            order.erase(it);
        } else if(cache.size() == capacity) {
            int lru_key = order.front();
            order.pop_front();
            cache.erase(lru_key);
        }
        cache[key] = value;
        order.push_back(key);
    }
};

class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxi = 0;
        for(int num : numSet) {
            if(numSet.find(num - 1) == numSet.end()) {
                int current = num;
                int count = 1;
                while(numSet.find(current + 1) != numSet.end()) {
                    current++;
                    count++;
                }
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};

class Solution {
  public:
    vector<int> lexSmallestNegatedPerm(int n, int target) {
        int sum = (int)n * (n + 1) / 2;
        if(sum < target || target < -sum || (sum - target) % 2 != 0) {
            return {};
        }
        int K = (sum - target) / 2;
        vector<bool> negated(n + 1, false);
        for(int i = n; i >= 1; i--) {
            if(K >= i) {
                negated[i] = true;
                K -= i;
            }
        }
        vector<int> ans;
        ans.reserve(n);
        for(int i = n; i >= 1; i--) {
            if(negated[i]) {
                ans.push_back(-i);
            }
        }
        for(int i = 1; i <= n; i++) {
            if(!negated[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

class Solution {
  public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int pf = 0;
        int cnt = 0;
        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            pf += nums[i];
            if(mp.count(pf - k)) {
                cnt += mp[pf - k];
            }
            mp[pf]++;
        }
        return cnt;
    }
};

class Solution {
  public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for(int i = 0; i < piles.size(); i++) {
                cnt += (piles[i] + mid - 1) / mid;
            }
            if(cnt > h) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};

class Solution {
  public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int zero_count = 0;
        int maxi = 0;
        for(int r = 0; r < n; r++) {
            if(nums[r] == 0) zero_count++;
            while(zero_count > k) {
                if(nums[l] == 0) zero_count--;
                l++;
            }
            maxi = max(maxi, r - l + 1);
        }
        return maxi;
    }
};

class Solution {
  public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        queue<pair<string, pair<int, int>>> q;
        q.push({"", {0, 0}});

        while(!q.empty()) {
            auto [s, counts] = q.front();
            q.pop();
            auto [open, close] = counts;

            if(s.size() == 2 * n) {
                ans.push_back(s);
                continue;
            }

            if(open < n) {
                q.push({s + "(", {open + 1, close}});
            }
            if(close < open) {
                q.push({s + ")", {open, close + 1}});
            }
        }

        return ans;
    }
};

class Solution {
  public:
    int maxProfit(vector<int>& inventory, int orders) {
        const int MOD = 1e9 + 7;
        sort(inventory.rbegin(), inventory.rend());
        inventory.push_back(0);
        int ans = 0;
        int n = inventory.size();
        int width = 1;
        for(int i = 0; i < n - 1 && orders > 0; i++) {
            int curr = inventory[i];
            int next = inventory[i + 1];
            if(curr > next) {
                int height = curr - next;
                int total = width * height;
                if(orders >= total) {
                    int sum = width * ((curr * (curr + 1LL) / 2) - (next * (next + 1LL) / 2));
                    ans = (ans + sum) % MOD;
                    orders -= total;
                } else {
                    int full = orders / width;
                    int rem = orders % width;
                    int low = curr - full;
                    int sum = width * ((curr * (curr + 1LL) / 2) - (low * (low + 1LL) / 2));
                    ans = (ans + sum) % MOD;
                    ans = (ans + rem * low) % MOD;
                    return ans;
                }
            }
            width++;
        }
        return ans;
    }
};

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            vector<int>& last = ans.back();
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            if(currStart <= last[1]) {
                last[1] = max(last[1], currEnd);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

class Solution {
  public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int asteroid : asteroids) {
            bool alive = true;
            while(alive && asteroid < 0 && !ans.empty() && ans.back() > 0) {
                int right = ans.back();
                if(right < -asteroid) {
                    ans.pop_back();
                } else if(right == -asteroid) {
                    ans.pop_back();
                    alive = false;
                } else {
                    alive = false;
                }
            }
            if(alive) ans.push_back(asteroid);
        }
        return ans;
    }
};

class Solution {
  public:
    string reverseWords(string s) {
        string word;
        string ans = "";
        stringstream stream(s);
        vector<string> v;
        while(stream >> word) {
            v.push_back(word);
        }
        int n = v.size();
        for(int i = 0; i < v.size(); i++) {
            if(i > 0) ans += " ";
            ans += v[n - i - 1];
        }
        return ans;
    }
};

class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0, col = n - 1;
        while(row < m && col >= 0) {
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] > target) col--;
            else
                row++;
        }
        return false;
    }
};

class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto i : nums) pq.push(i);
        int ans = 0;
        while(k--) {
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};

class Solution {
  public:
    string helper(int n, string s) {
        if(n == 1) return s;
        string temp = "";
        int i = 0;
        while(i < (int)s.size()) {
            char curr = s[i];
            int count = 0;
            while(i < (int)s.size() && s[i] == curr) {
                count++;
                i++;
            }
            temp += to_string(count);
            temp += curr;
        }
        return helper(n - 1, temp);
    }
    string countAndSay(int n) {
        return helper(n, "1");
    }
};

class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, int> mp;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) { mp[i * 1000 + j]++; }
            }
        }
        for(auto& it : mp) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][it.first % 1000] = 0;
            }
            for(int i = 0; i < matrix[0].size(); i++) {
                matrix[it.first / 1000][i] = 0;
            }
        }
    }
};

class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();
        int prev = 0;
        for(int i = 1; i < m; i++) {
            if(matrix[i][0] > target) {
                break;
            }
            prev = i;
        }
        int l = 0, high = n - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(matrix[prev][mid] == target) return true;
            if(matrix[prev][mid] > target) h = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};

class Solution {
  public:
    vector<int> subset;
    vector<vector<int>> ans;
    vector<int> nums;
    void dfs(int i) {
        if(i >= nums.size()) {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(i + 1);

        subset.pop_back();
        dfs(i + 1);
    }
    vector<vector<int>> subsets(vector<int>& input_nums) {
        nums = input_nums
            dfs(0);
        return ans;
    }
};

class Solution {
  public:
    double separateSquares(vector<vector<int>>& squares) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        double totalArea = 0;
        double low = 1e18, high = -1e18;

        for(auto& sq : squares) {
            double y = sq[1];
            double l = sq[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double target = totalArea / 2.0;

        for(int iter = 0; iter < 100; iter++) {
            double mid = (low + high) / 2.0;
            double areaBelow = 0;

            for(auto& sq : squares) {
                double y = sq[1];
                double l = sq[2];
                double top = y + l;

                if(mid <= y) continue;
                else if(mid >= top)
                    areaBelow += l * l;
                else
                    areaBelow += l * (mid - y);
            }

            if(areaBelow < target) low = mid;
            else
                high = mid;
        }

        return low;
    }
};  
