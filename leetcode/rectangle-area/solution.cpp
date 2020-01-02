class Solution {
public:
    int computeArea(int A, int B, int C, int D, 
                    int E, int F, int G, int H) {
        if (A > E) {
            std::swap(A, E);
            std::swap(B, F);
            std::swap(C, G);
            std::swap(D, H);
        }
        int areaRec1 = (C - A) * (D - B);
        int areaRec2 = (G - E) * (H - F);
        int overlapArea = (C < E || A > G || B > H || D < F) ? 0 : (std::min(C, G) - E) * (std::min(D, H) - std::max(B, F));
        
        return areaRec1 - overlapArea + areaRec2;
    }
};
