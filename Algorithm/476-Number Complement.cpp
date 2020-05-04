class Solution {
public:
    int findComplement(int num) {
//        int mask = 1;
//        while(mask < num)
//            mask = (mask << 1) + 1;
//        return num ^ mask;        
        int ret = 0, cnt = 0;
        while(num) {
            ret |= ((num & 1) ^ 1) << cnt;
            num >>= 1;
            ++cnt;
        }
        return ret;
    }
};
