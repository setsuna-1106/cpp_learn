class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1]; 
        });
        
        int maxUnits = 0;
        
        for (const auto& box : boxTypes) {
            if (truckSize <= 0) {
                break;
            }
            
            int numberOfBoxes = box[0];
            int unitsPerBox = box[1];
            if (numberOfBoxes <= truckSize) {
                maxUnits += numberOfBoxes * unitsPerBox;
                truckSize -= numberOfBoxes;
            } 

            else {
                maxUnits += truckSize * unitsPerBox;
                truckSize = 0;
            }
        }
        
        return maxUnits;
    }
};