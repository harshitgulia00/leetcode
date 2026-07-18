class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 0;
        int end = arr.size() - 1;
        int mid;
        while(st <= end){
            mid = st + (end - st)/2;
            if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]){
                return mid;
            }
            if(arr[mid] <= arr[mid + 1]){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return 0;
    }
};