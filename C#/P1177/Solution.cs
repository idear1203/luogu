using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public void QuickSort(int[] nums) 
    {
        if (nums == null || nums.Length == 0)
        {
            return;
        }

        QuickSort(nums, 0, nums.Length - 1);
    }

    private void QuickSort(int[] nums, int start, int end)
    {
        if (start >= end)
        {
            return;
        }

        int pivot = nums[start];
        int i = start;
        int j = end;
        while (i < j)
        {
            while (i < j && nums[j] >= pivot)
            {
                j--;
            }

            while (i < j && nums[i] <= pivot)
            {
                i++;
            }

            if (i < j)
            {
                Swap(nums, i, j);
            }
        }

        Swap(nums, start, i);

        QuickSort(nums, start, i - 1);
        QuickSort(nums, i + 1, end);
    }

    private void Swap(int[] nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    // TLE
    public static void Main(string[] args)
    {
        // Skip the first line. It is the amount of numbers.
        string line = Console.ReadLine();
        var nums = Console.ReadLine().Split(' ').Select(str => Convert.ToInt32(str)).ToArray();

        var solution = new Solution();
        solution.QuickSort(nums);
        System.Console.WriteLine(string.Join(" ", nums.Select(num => num.ToString()))); 
    }
}