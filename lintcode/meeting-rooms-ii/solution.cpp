/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;   
        });

        int numMeetingRooms = 0;
        auto comp = [](const Interval& a, const Interval& b) {
            return a.end > b.end;
        };
        std::priority_queue<Interval, vector<Interval>, decltype(comp)> queue(comp);
        
        for (auto& interval: intervals) {
            while(!queue.empty() && queue.top().end <= interval.start) {
                queue.pop();
            }
            queue.push(interval);
            numMeetingRooms = std::max(numMeetingRooms, (int)queue.size());
        }
        
        return numMeetingRooms;
    }
};
