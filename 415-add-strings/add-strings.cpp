class Solution {
public:
    string addStrings(string a, string b) {
        int i = a.size() - 1;   // last index of a
        int j = b.size() - 1;   // last index of b
        int carry = 0;          // carry value // Carry = extra value that goes to the next digit when sum ≥ 10

        string res = "";

        // loop till both strings end
        while (i >= 0 || j >= 0) {
            int sum = carry;

            // add digit a
            if (i >= 0) {
                sum += a[i] - '0'; // char to int
                i--;
            }

            // add digit b
            if (j >= 0) {
                sum += b[j] - '0'; // char to int
                j--;
            }

            res += char(sum % 10 + '0'); // store digit
            carry = sum / 10;            // update carry
        }

        // if carry left
        if (carry) {
            res += char(carry + '0');
        }

        reverse(res.begin(), res.end()); // reverse answer
        return res;
    }
};



// int sum = digit1 + digit2 + carry;
//carry = sum / 10;   // extra part
// digit = sum % 10;   // current digit