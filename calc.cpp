#include <bits/stdc++.h>
using namespace std;


int calculate(const vector<string>& nums) {
    int a = nums.size();
    int z = stoi(nums[0]);
    for (int i = 1; i < a; i += 2) {
        char c = nums[i][0];
        int y = stoi(nums[i + 1]);
        if (c == '+')
            z += y;
        else if (c == '-')
            z -= y;
        else if (c == 'X')
            z *= y;
        else if (c == 'D')
            z /= y;
    }
    return z;
}

int main() {
    bool fla = true;
    vector<string> ans;
    int ts = 0;
    bool readingNum = false;

    while (fla) {
        char c;
        cin >> c;

        if (isdigit(c)) {
            ts = ts * 10 + (c - '0');
            readingNum = true;
        } 
        else {
            if (readingNum) {
                ans.push_back(to_string(ts));
                ts = 0;
                readingNum = false;
            }

            if (c == '=') {
                fla = false;
                break;
            }

            ans.push_back(string(1, c));
        }
    }

    if (readingNum) ans.push_back(to_string(ts));

    cout << "Result: " << calculate(ans) << endl;
    return 0;
}
