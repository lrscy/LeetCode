class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> st;
        st.insert( -100000 ); st.insert( 100000 );
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pos;
        for( int i = 0; i < flowers.size(); ++i ) {
            pos.push( make_pair( i + 1, flowers[i] ) );
        }
        while( !pos.empty() ) {
            auto tp = pos.top(); pos.pop();
            auto it = st.lower_bound( tp.second ), tit = it;
            int lo = *( --tit ), hi = *it;
            int dlo = tp.second - lo - 1, dhi = hi - tp.second - 1;
            if( dlo == k || dhi == k ) return tp.first;
            st.insert( tp.second );
        }
        return -1;
    }
};
