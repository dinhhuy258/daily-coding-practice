/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &A) {
    if (A.empty()) {
        return {};
    }
    std::sort(A.begin(), A.end(), [](const Interval& a, const Interval& b) -> bool { 
        return a.start < b.start; 
    });
    std::vector<Interval> result;
    Interval interval(A[0].start, A[0].end);
    for (int i = 1; i < A.size(); ++i) {
        if (A[i].start > interval.end) {
            result.push_back(interval);
            interval.start = A[i].start;
            interval.end = A[i].end;
        }
        else {
            interval.end = std::max(interval.end, A[i].end);
        }
    }
    result.push_back(interval);
    return result;
}
