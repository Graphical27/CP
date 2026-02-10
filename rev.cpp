
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