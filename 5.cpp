// Manacher's Algorithm:  https://segmentfault.com/a/1190000003914228

// Time: O(n^2)
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


string longestPalindrome(string s) {
    double radius = 0;
    double pos = 0;
    int len = s.size();
    
    
    for (double i = 0; i < len; i += 0.5) {
        double r = 0;
        while (i - r >= 0 && i + r < len
               && s[floor(i - r)] == s[ceil(i + r)]) {
            r += 0.5;
        }
        
        if (r > radius) {
            radius = r;
            pos = i;
        }
    }
    cout << "pos:" << pos << endl << "radius:" << radius << endl;
    return s.substr(ceil(pos - radius), radius * 2);
}

int main(int argc, const char * argv[]) {
    string input("abba");
    cout << longestPalindrome(input) << endl;
    return 0;
}
