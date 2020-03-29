using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public List<string> GetResult(string input) 
    {
        if (string.IsNullOrEmpty(input))
        {
            return new List<string>();
        }

        var scores = new List<string>();
        int endFlagIdx = input.IndexOf('E');
        input = endFlagIdx >= 0 ? input.Substring(0, endFlagIdx) : input;

        scores.AddRange(GetResult(input, 11));
        scores.Add(string.Empty);
        scores.AddRange(GetResult(input, 21));
        return scores;
    }

    private IEnumerable<string> GetResult(string input, int total)
    {
        int wCount = 0;
        int lCount = 0;
        foreach (var ch in input)
        {
            switch(ch)
            {
                case 'W': wCount++; break;
                case 'L': lCount++; break;
                default: break;
            }

            if ((lCount >= total || wCount >= total) && Math.Abs(lCount - wCount) >= 2)
            {
                yield return $"{wCount}:{lCount}";
                lCount = 0;
                wCount = 0;
            }
        }

        yield return $"{wCount}:{lCount}";
    }

    public static void Main(string[] args)
    {
        string input = null;
        string line;
        while ((line = Console.ReadLine()) != null && line != "")
        {
            input += line;
        }

        var solution = new Solution();
        var outputs = solution.GetResult(input);
        foreach (var output in outputs)
        {
            System.Console.WriteLine(output);
        }
    }
}