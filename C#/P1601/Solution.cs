using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Solution
{
    public string GetResult(string a, string b) 
    {
        int aIdx = a.Length - 1;
        int bIdx = b.Length - 1;
        int carry = 0;
        var sb = new StringBuilder();
        while (aIdx >= 0 || bIdx >= 0 || carry > 0) 
        {
            int aNum = aIdx >= 0 ? a[aIdx--] - '0' : 0;
            int bNum = bIdx >= 0 ? b[bIdx--] - '0' : 0;
            int num = (aNum + bNum + carry) % 10;
            carry = (aNum + bNum + carry) / 10;
            sb.Insert(0, num.ToString());
        }

        return sb.ToString();
    }

    public static void Main(string[] args)
    {
        string a = Console.ReadLine();
        string b = Console.ReadLine();

        var solution = new Solution();
        System.Console.WriteLine(solution.GetResult(a, b));
    }
}