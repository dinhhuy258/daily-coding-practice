class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int shift = 0;
        for (int i = S.size() - 1; i >= 0; --i) {
            shift = (shifts[i] % 26 + shift) % 26;
            S[i] = ((S[i] - 'a') + shift)  % 26 + 'a';
        }

        return S;
    }
};

