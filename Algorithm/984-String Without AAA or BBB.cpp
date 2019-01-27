class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string s = "";
        int a = 0, b = 0;
        while( A || B ) {
            int ta = 0, tb = 0;
            while( ta < 2 && B <= 2 * A && A > 0 ) { s += "a"; ++ta; --A; }
            while( tb < 2 && A <= 2 * B && B > 0 ) { s += "b"; ++tb; --B; }
        }
        return s;
    }
};
