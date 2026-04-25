class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size()) swap(A, B); // ensure A is the smaller
        int m = A.size(), n = B.size();
        int total = m + n;
        int half = total / 2;

        const int INF = 2e9;
        int low = 0, high = m;

        while (low <= high) {
            int i = (low + high) / 2;
            int j = half - i; // left count from B

            int Aleft  = (i > 0) ? A[i - 1] : -INF;
            int Aright = (i < m) ? A[i] : INF;
            int Bleft  = (j > 0) ? B[j - 1] : -INF;
            int Bright = (j < n) ? B[j] : INF;

            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 == 1) {
                    return (double)min(Aright, Bright);
                } else {
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                }
            } else if (Aleft > Bright) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        return 0.0; // should not reach with valid inputs
    }
};