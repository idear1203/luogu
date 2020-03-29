using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;

public class Solution
{
    private void RadixSort(int[] nums, int max)
    {
        if (nums == null || nums.Length == 0)
        {
            return;
        }

        int radix = 1;
        int d = 10;
        int[] aux = new int[nums.Length];

        while (max / radix > 0)
        {
            int[] counts = new int[d];
            for (int i = 0; i < nums.Length; i++)
            {
                counts[nums[i] / radix % d]++;
            }

            for (int i = 1; i < d; i++)
            {
                counts[i] += counts[i - 1];
            }

            for (int i = nums.Length - 1; i >= 0; i--)
            {
                aux[--counts[nums[i] / radix % d]] = nums[i];
            }

            for (int i = 0; i < nums.Length; i++)
            {
                nums[i] = aux[i];
            }

            radix *= d;
        }
    }

    // TLE
    public static void Main(string[] args)
    {
        string line = Console.ReadLine();
        string[] parts = line.Split(' ');
        int n = Convert.ToInt32(parts[0]);
        int m = Convert.ToInt32(parts[1]);
        int[] nums = new int[m];
        parts = Console.ReadLine().Split(' ');
        for (int i = 0; i < m; i++)
        {
            nums[i] = Convert.ToInt32(parts[i]);
        }

        var solution = new Solution();
        solution.RadixSort(nums, n);
        if (m > 0)
        {
            for (int i = 0; i < m - 1; i++)
            {
                System.Console.Write("{0} ", nums[i]);
            }

            System.Console.WriteLine($"{nums[m - 1]}");
        }
    }
}