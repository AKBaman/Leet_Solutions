class Solution {
public:
    int removePair(string& s, char first, char second, int val) {
        stack<char> st;
        int profit = 0;
        for (char c : s) {
            if (!st.empty() && st.top() == first && c == second) {
                st.pop();
                profit += val;
            } else {
                st.push(c);
            }
        }

        // Rebuild string from remaining stack
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return profit;
    }

    int maximumGain(string s, int x, int y) {
        int totalProfit = 0;

        // Prioritize the more profitable pair
        if (x >= y) {
            totalProfit += removePair(s, 'a', 'b', x);
            totalProfit += removePair(s, 'b', 'a', y);
        } else {
            totalProfit += removePair(s, 'b', 'a', y);
            totalProfit += removePair(s, 'a', 'b', x);
        }

        return totalProfit;
    }
};
