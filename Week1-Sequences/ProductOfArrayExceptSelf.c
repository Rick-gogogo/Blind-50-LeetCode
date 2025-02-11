/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//Write an algorithm that runs in O(n) time and without using the division operation.
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {

    int* result = (int*)malloc(sizeof(int)*numsSize);
    result[0] = 1;
    //left 
    for( int i = 1; i < numsSize; i++){
        result[i] = result[i-1] * nums[i-1];
    }   
    //test
    for(int i = 0 ; i< numsSize; i++){
        printf("{%d}",result[i]);
    }
    //right
    int temp = 1;
    for(int j = (numsSize-2); j >= 0; j--){
        temp = temp * nums[j+1];
        result[j] = result[j] * temp;
    }
    //
     for(int i = 0 ; i< numsSize; i++){
        printf("{%d}",result[i]);
    }   

    *returnSize = numsSize;
    return result;
}
