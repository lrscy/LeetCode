/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#pragma GCC optimize("O3")
static const auto __ = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        multiset<int> st;
        int cnt = 0;
        sort( intervals.begin(), intervals.end(), cmp );
        for( auto i : intervals ) {
            auto it = st.upper_bound( i.start );
            if( it == st.end() ) {
                st.clear();
                st.insert( i.end );
            } else {
                st.erase( st.begin(), it );
                st.insert( i.end );
            }
            if( cnt < st.size() ) cnt = st.size();
        }
        return cnt;
    }
    
    static bool cmp( const Interval &a, const Interval &b ) {
        return a.start == b.start ? a.end < b.end : a.start < b.start;
    }
};
