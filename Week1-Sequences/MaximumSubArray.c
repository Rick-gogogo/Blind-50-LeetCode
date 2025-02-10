//Made it after debugging twice for minior mistake
int getBig(int* nums, int numsSize, int temp_numsSize, int index, int largest_sum, int temp){

    for( int i = index; i < temp_numsSize; i++){
        temp += nums[i];
    }
    if(temp > largest_sum){
        largest_sum = temp;
    }
    temp_numsSize = temp_numsSize +1;

    if(temp_numsSize > numsSize){
      // printf("{%d}", largest_sum);
        return largest_sum;
    }
    return getBig(nums, numsSize,temp_numsSize, index,largest_sum , 0);

}

int maxSubArray(int* nums, int numsSize) {

    int largest_sum = nums[0];
    for(int i =0 ; i< numsSize; i++){
        int t_largest_sum =   getBig(nums, numsSize, i+1, i, largest_sum, 0);
        if(t_largest_sum > largest_sum){
            largest_sum = t_largest_sum;
        }
    }
    printf("largest_sum: %d",largest_sum);
    return largest_sum;
}
