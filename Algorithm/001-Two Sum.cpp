class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> mp;
        for( int i = 0; i < nums.size(); ++i ) {
            int a = target - nums[i];
            if( mp.count( a ) && mp[a] != i ) {
                ret.push_back( i );
                ret.push_back( mp[a] );
                break;
            }
            mp[nums[i]] = i;
        }
        return ret;
    }
};
