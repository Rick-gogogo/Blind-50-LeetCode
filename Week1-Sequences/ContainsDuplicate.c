bool containsDuplicate(int* nums, int numsSize) {
    if(nums == NULL || numsSize <=0){
        return false;
    }
    for(int i =0; i<numsSize; i++){
            for(int j=0;j<numsSize; j++){
                if( i != j && nums[i] == nums[j]){
                    return true;
                }
            }
    }
    return false;
}
