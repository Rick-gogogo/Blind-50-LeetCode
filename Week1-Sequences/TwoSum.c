/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, 
int* returnSize) {

  int RETURN_SIZE = 2;
  
  *returnSize = RETURN_SIZE;
  int* result = (int*)malloc(RETURN_SIZE * sizeof(int));
  if (result == NULL) {
      return NULL;
  }
  
  int index_0 = 0;
  int index_1 = 0;
  int boolean_should_break = 0;
  for(int i =0; i < numsSize;i++){
      //For performance
      if(nums[i] >= target){
         continue;
      }
  
      for(int j= 0; j < numsSize;j++){
          if(i==j){
              continue;
          }
          int temp = nums[i] + nums[j];
  
          if( temp == target){
              index_0 = i;
              index_1 = j;
              boolean_should_break = 1;
              break;
          }
      }
      if(boolean_should_break == 1){
          break;
      }
  
  }
  
  result[0]  = index_0;
  result[1] = index_1;
  return result;
}
