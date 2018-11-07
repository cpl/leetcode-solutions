int search(int* nums, int numsSize, int target) {
    if(numsSize == 0 || target < nums[0] || target > nums[numsSize-1])
        return -1;

    int l = 0, r = numsSize - 1;
    int m;

    while(l <= r) {   
        m = (l+r)/2;
        
        if(nums[m] == target)
            return m;
        
        if(nums[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }
    
    return -1;
}
