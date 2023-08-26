/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string ra(a), rb(b), ans;

        reverse(ra.begin(), ra.end());
        reverse(rb.begin(), rb.end());

        int sizea = ra.size(), sizeb = rb.size();
        int ia = 0, ib = 0, ians = 0, inta = 0, intb = 0, tmp = 0;
        int carry = 0;

        while(ia < sizea && ib < sizeb)
        {
            inta = (int) (ra[ia] - '0');
            intb = (int) (rb[ib] - '0');
            tmp = inta + intb + carry;

            if(tmp > 1)
            {
                carry = 1;
                ans.push_back((char)('0' + (tmp - 2)));
            }
            else
            {
                carry = 0;
                ans.push_back((char)('0' + tmp));
            }

            ia++;ib++;
        }

        while(ia < sizea)
        {
            inta = (int) (ra[ia] - '0');
            tmp = inta + carry;
            
            if(tmp > 1)
            {
                carry = 1;
                ans.push_back((char)('0' + (tmp - 2)));
            }
            else
            {
                carry = 0;
                ans.push_back((char)('0' + tmp));
            }

            ia++;
        }

        while(ib < sizeb)
        {
            intb = (int) (rb[ib] - '0');
            tmp = intb + carry;
            
            if(tmp > 1)
            {
                carry = 1;
                ans.push_back((char)('0' + (tmp - 2)));
            }
            else
            {
                carry = 0;
                ans.push_back((char)('0' + tmp));
            }

            ib++;
        }

        if(carry == 1)
        {
            ans.push_back('1');
        }
        
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
// @lc code=end

