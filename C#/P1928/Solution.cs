using System;
using System.Collections.Generic;
using System.Text;

enum ItemType
{
    String = 1,
    Number = 2
}

class Item
{
    public string Content { get; set; }
    public ItemType Type { get; set; }
}

class Solution
{
    private string GetResult(string input)
    {
        if (string.IsNullOrEmpty(input))
        {
            return string.Empty;
        }

        // Add an ']' at the end to enforce stack pop
        input += ']';

        var stack = new Stack<Item>();
        int idx = 0;
        while (idx < input.Length)
        {
            string part = ReadInput(input, ref idx);
            if (part == "[")
            {
                // do nothing
            }
            else if (part == "]")
            {
                string str = string.Empty;
                while (stack.Count > 0 && stack.Peek().Type == ItemType.String)
                {
                    str = stack.Pop().Content + str;
                }

                int count = 1;
                if (stack.Count > 0 && stack.Peek().Type == ItemType.Number)
                {
                    count = Convert.ToInt32(stack.Pop().Content);
                }

                stack.Push(new Item
                {
                    Content = Repeat(str, count),
                    Type = ItemType.String
                });
            }
            else if (char.IsDigit(part[0]))
            {
                stack.Push(new Item
                {
                    Content = part,
                    Type = ItemType.Number
                });
            }
            else if (!string.IsNullOrEmpty(part))
            {
                stack.Push(new Item
                {
                    Content = part,
                    Type = ItemType.String
                });
            }
        }

        return stack.Count > 0 ? stack.Pop().Content : string.Empty;
    }

    private string Repeat(string input, int count)
    {
        var sb = new StringBuilder();
        for (int i = 0; i < count; i++)
        {
            sb.Append(input);
        }

        return sb.ToString();
    }

    private string ReadInput(string input, ref int startIdx)
    {
        if (startIdx >= input.Length)
        {
            string part = input.Substring(startIdx, input.Length - startIdx);
            startIdx = input.Length;
            return part;
        }

        int curIdx = startIdx;
        if (input[curIdx] == '[' || input[curIdx] == ']')
        {
            string part = input[curIdx].ToString();
            startIdx = curIdx + 1;
            return part;
        }
        else if (char.IsDigit(input[curIdx]))
        {
            while (char.IsDigit(input[curIdx]))
            {
                curIdx++;
            }

            string part = input.Substring(startIdx, curIdx - startIdx);
            startIdx = curIdx;
            return part;
        }
        else
        {
            while (char.IsLetter(input[curIdx]))
            {
                curIdx++;
            }

            string part = input.Substring(startIdx, curIdx - startIdx);
            startIdx = curIdx;
            return part;
        }
    }

    static void Main(string[] args)
    {
        string input = Console.ReadLine();
        string output = new Solution().GetResult(input);
        Console.WriteLine(output);
    }
}