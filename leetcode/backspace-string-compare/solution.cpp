class Solution {
public:
    bool backspaceCompare(std::string S, std::string T) {
        int i = S.size();
        int j = T.size();
        
        while (i >= 0 && j >= 0) {
            while (i >= 0 && S[i] == '#') {
                int numberBackspace = 0;
                do {
                    numberBackspace += S[i] == '#' ? 1 : -1;
                    --i;
                }
                while (numberBackspace > 0 && i >= 0);
            }
            
            while (j >= 0 && T[j] == '#') {
                int numberBackspace = 0;
                do {
                    numberBackspace += T[j] == '#' ? 1 : -1;
                    --j;
                }
                while (numberBackspace > 0 && j >= 0);
            }
            
            if (i >= 0 && j >= 0 && S[i--] != T[j--]) {
                return false; 
            }
        }
        if (i >= 0 && S[i] == '#') {
            int numberBackspace = 0;
            do {
                numberBackspace += S[i] == '#' ? 1 : -1;
                --i;
            }
            while (numberBackspace > 0 && i >= 0);
        }
        
        if (j >= 0 && T[j] == '#') {
            int numberBackspace = 0;
            do {
                numberBackspace += T[j] == '#' ? 1 : -1;
                --j;
            }
            while (numberBackspace > 0 && j >= 0);
        }
              
        return i == j;
    }
};
