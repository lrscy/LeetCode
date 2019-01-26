class Solution {
public:
    string numberToWords(int num) {
        if( !num ) return digits[0];
        int nums[10];
        int cnt = 0;
        while( num ) {
            nums[cnt++] = num % 1000;
            num /= 1000;
        }
        string str = "";
        while( --cnt >= 0 ) {
            str += toEng( nums[cnt], cnt );
        }
        return str.substr( 0, str.length() - 1 );
    }
    
    string toEng( int num, int scale ) {
        string str = "";
        int d, ori = num;
        d = num / 100;
        if( d ) str += digits[d] + " " + scales[0] + " ";
        num -= d * 100;
        if ( num / 10 == 1 ) {
            str += tendigits[num - 10] + " ";
        } else {
            d = num / 10;
            if( d ) str += tens[d] + " ";
            d = num % 10;
            if( d ) str += digits[d] + " ";
        }
        if( ori && scale ) str += scales[scale] + " ";
        return str;
    }
private:
    string digits[15] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                        "Eight", "Nine" };
    string tens[15] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
                        "Eighty", "Ninety" };
    string tendigits[15] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                        "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    string scales[5] = { "Hundred", "Thousand", "Million", "Billion" };
};
