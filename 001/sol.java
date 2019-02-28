
import java.util.*;

class TwoSumProblem{
  public static boolean twoSum(int[] nums, int target){
    Set<Integer> comps = new HashSet<>();
    for (int i=0; i<nums.length; i++){
      if (comps.contains(nums[i])){
        return true;
      }
      comps.add(target-nums[i]);
    }
    return false;
  }

  public static void main(String args[]){
    int[] nums = {2, 7, 5, 11, -7, 6, -131};
    int target = 1;
    System.out.println(twoSum(nums, target));
  }
}
