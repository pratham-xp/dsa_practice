class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int leftIdx = 0, rightIdx = numbers.length - 1;

        while(leftIdx < rightIdx){
            if(numbers[leftIdx] + numbers[rightIdx] > target){
                rightIdx--;
            } else if (numbers[leftIdx] + numbers[rightIdx] < target){
                leftIdx++;
            } else { break; }
        }
        return  new int[]{leftIdx + 1, rightIdx + 1};
    }
}
