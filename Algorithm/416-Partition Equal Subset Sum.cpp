static int desyncio = []() {
    std::ios::sync_with_stdio( false );
    cin .tie( nullptr );
    cout.tie( nullptr );
    return 0;
}();

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<20010> bs(1);
        int sum = 0;
        for(auto n: nums) sum += n;
        if(sum & 1) return false;
        for(auto n: nums) {
            bs |= (bs << n);
        }
        return bs[sum >>= 1];
    }
};

/*
class Solution {
public:
    bool dp[20010];
    bool canPartition(vector<int>& nums) {
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        int sum = 0;
        for(auto n: nums) sum += n;
        if(sum & 1) return false;
        sum /= 2;
        for(auto n: nums) {
            for(int i = sum; i >= n; --i) {
                if(dp[i - n])
                    dp[i] = true;
            }
        }
        return dp[sum];
    }
};
 */
