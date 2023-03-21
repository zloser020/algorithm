#include<iostream>
#include<unordered_map>
using namespace std;
#include<vector>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int>hashmap;
        for (int num : nums) {
            if (hashmap.find(num) == hashmap.end()) {
                hashmap.insert(make_pair(num, 1));
            }
            else {
                hashmap[num] = hashmap[num] + 1;
            }
        }
        for (int num : nums) {
            if (hashmap[num] == 1)
                return num;
        }
        return 0;
    }
};