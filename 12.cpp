class Solution {
public:
    // 将一位数字根据1、5、10的字符转换为罗马数字
    string convert(int num, string i, string v, string x) {
        string str = "";
        while (num != 0) {
            if (num >= 9) {
                str.append(x);
                num -= 10;
            }
            else if (num >= 4) {
                str.append(v);
                num -= 5;
            }
            else if (num >= 1) {
                str.append(i);
                num -= 1;
            }
            else if (num < 0) {
                str.insert(0, i);
                num += 1;
            }
        }
        return str;
    }

    string intToRoman(int num) {
        unordered_map<int, string> map = {{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"},
            {100, "C"}, {500, "D"}, {1000, "M"}, {5000, ""}, {10000, ""}};

        string romanStr = "";
        int i = 1, v = 5, x = 10;

        while(num != 0) {
            int n = num % 10;
            romanStr.insert(0, convert(n , map[i], map[v], map[x]));
            num /= 10;
            i *= 10;
            v *= 10;
            x *= 10;
        }
        return romanStr;
    }
};
