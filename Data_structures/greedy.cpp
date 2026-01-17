
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:

    static bool compare(const vector<int> &int1 ,const vector<int> &int2){
        return int1[1] < int2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        if(intervals.empty()) return 0;
        sort(intervals.begin() , intervals.end(), compare);

        int count = 1;

        int freeTime = intervals[0][1];

        for(int i = 1 ; i < intervals.size() ;i++){
                if(intervals[i][0] >=  freeTime){
                    count++;
                    freeTime = intervals[i][1];
                }
        }


        return intervals.size() - count;
    }
};

class maximum {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    
    typedef struct Data{
        int start;
        int end;
    }Data;
   
   
   static bool comapre(Data &d1 , Data &d2){
       return d1.end < d2.end;
   }
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        
        int n = start.size();
        
        vector<Data> arr(n);
        
        
        for(int i = 0 ; i < n ; i++){
            arr[i].start = start[i];
            arr[i].end   = end[i];
        }
        
        sort(arr.begin() , arr.end(),comapre);
        
        int freeTime = arr[0].end;  int count = 1;
        
        for(int i = 1 ; i < n ;i++){
            if(arr[i].start > freeTime){
                count++;
                freeTime = arr[i].end;
            }
        }
        
        
        return count;
        
    }
};