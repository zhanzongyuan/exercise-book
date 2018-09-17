/**
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        int i = 0;
        bool merged = false;
        while (i < intervals.size()) {
            if (intervals[i].start <= newInterval.end && intervals[i].end >= newInterval.start) {
                int l = min(intervals[i].start, newInterval.start);
                int r = max(intervals[i].end, newInterval.end);
                i++;

                while (i < intervals.size() && intervals[i].start <= newInterval.end && intervals[i].end >= newInterval.start) {
                    l = min(l, min(intervals[i].start, newInterval.start));
                    r = max(r, max(intervals[i].end, newInterval.end));
                    i++;
                }
                result.push_back(Interval(l, r));
                merged = true;
            }
            else if (!merged && newInterval.end < intervals[i].start) {
                result.push_back(newInterval);
                result.push_back(intervals[i]);
                merged = true;
                i++;
            }
            else {
                result.push_back(intervals[i]);
                i++;
            }
        }

        if (!merged) result.push_back(newInterval);
        return result;
    }
};
