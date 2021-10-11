#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> singles = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string numberToWord(int num) {
        if (num == 0) return "Zero";
        string sb;
        for (int i = 3, unit = 1e9; i >= 0; i--, unit /= 1000) {
            int curNum = num / unit;
            if (curNum != 0) {
                num = num - curNum * unit;
                string cur;
                recursion(cur, num);
                cur = cur + thousands[i] + " ";
                sb += cur;
            }
        }
        while (sb.back() == ' ') {
            sb.pop_back();
        }
        return sb;
    }

    void recursion(string& cur, int num) {
        if (num == 0) return;
        else if (num < 10) {
            cur = cur + singles[num] + " ";
        }
        else if (num < 20) {
            cur = cur + teens[num % 10] + " ";
        }
        else if (num < 100) {
            cur = cur + tens[num/10] + " ";
            recursion(cur, num % 10);
        }
        else {
            cur = cur + teens[num / 100] + "Hundred" + " ";
            recursion(cur, num % 100);
        }
    }
};