using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public int GetResult(int[] nums) 
    {
        if (nums == null || nums.Length == 0)
        {
            return 0;
        }

        RadixSort(nums);

        // Remove duplicates.
        int n = 1;
        for (int i = 1; i < nums.Length; i++)
        {
            if (nums[i] != nums[n - 1])
            {
                nums[n++] = nums[i];
            }
        }

        return n;
    }

    private void RadixSort(int[] nums)
    {
        int max = nums.Max();
        int[] aux = new int[nums.Length];
        int d = 10;
        int radix = 1;
        while (max / radix > 0)
        {
            var counts = new int[d];
            for (int i = 0; i < nums.Length; i++)
            {
                counts[nums[i] / radix % d]++;
            }

            for (int i = 1; i < d; i++)
            {
                counts[i] += counts[i - 1];
            }

            // ATTENTION: from back to keep order.
            for (int i = nums.Length - 1; i >= 0; i--)
            {
                aux[--counts[nums[i] / radix % d]] = nums[i];
            }

            // Copy back to original array.
            for (int i = 0; i < nums.Length; i++)
            {
                nums[i] = aux[i];
            }

            radix *= d;
        }
    }

    public static void Main(string[] args)
    {
        // Skip the first line. It is the amount of numbers.
        string line = Console.ReadLine();
        var nums = Console.ReadLine().Split(' ').Select(str => Convert.ToInt32(str)).ToArray();

        var solution = new Solution();
        int n = solution.GetResult(nums);
        System.Console.WriteLine(n);
        System.Console.WriteLine(string.Join(" ", nums.Take(n).Select(num => num.ToString()))); 
    }
}