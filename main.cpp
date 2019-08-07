#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

// https://leetcode.com/problems/count-binary-substrings/

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    // continuous number of 0s and 1s grouped together
    // "10101" => [1, 1, 1, 1, 1]
    // "110001111000000" => [2, 3, 4, 6]
    // groups next to each other added using min
    int countBinarySubstrings(string &s) {
        if (s.length() <= 1) return 0;
        vector<int> v;
        int count = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                ++count;
            } else {
                v.push_back(count);
                count = 1;
            }
        }
        v.push_back(count);
        if (v.size() <= 1) return 0;
        int mx = 0;
        for (int i = 1; i < v.size(); ++i) {
            mx += min(v[i], v[i - 1]);
        }
        return mx;
    }
};

void test1() {
    string s = "00110011";

    cout << "6 ? " << Solution().countBinarySubstrings(s) << endl;
}

void test2() {

}

void test3() {

}