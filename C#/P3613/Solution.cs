using System;
using System.Collections.Generic;

public class Solution
{
    public static void Main(string[] args)
    {
        var map = new Dictionary<int, int>();
        var parts = Console.ReadLine().Split(' ');
        int q;
        q = Convert.ToInt32(parts[1]);
        while (q-- > 0)
        {
            parts = Console.ReadLine().Split(' ');
            int op = Convert.ToInt32(parts[0]);
            int i = Convert.ToInt32(parts[1]);
            int j = Convert.ToInt32(parts[2]);
            if (op == 1)
            {
                map[i * 100000 + j] = Convert.ToInt32(parts[3]);
            }
            else
            {
                Console.WriteLine(map[i * 100000 + j]);
            }
        }
    }
}
