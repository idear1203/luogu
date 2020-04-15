using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public int getResult(string line)
    {
        var parts = Parse(line).ToList();
        var stack = new Stack<int>();
        foreach (string sym in parts)
        {
            if (char.IsDigit(sym[0]))
            {
                stack.Push(Convert.ToInt32(sym));
            }
            else
            {
                char op = sym[0];
                if (op == '@')
                {
                    if (stack.Count == 0)
                    {
                        return 0;
                    }

                    return stack.Pop();
                }
                else
                {
                    int operand2 = stack.Pop();
                    int operand1 = stack.Pop();
                    if (op == '+')
                    {
                        stack.Push(operand1 + operand2);
                    }
                    else if (op == '-')
                    {
                        stack.Push(operand1 - operand2);
                    }
                    else if (op == '*')
                    {
                        stack.Push(operand1 * operand2);
                    }
                    else if (op == '/')
                    {
                        stack.Push(operand1 / operand2);
                    }
                }
            }
        }

        return 0;
    }

    private IEnumerable<string> Parse(string line)
    {
        var parts = line.Split('.');
        for (int i = 0; i < parts.Length; i++)
        {
            string sym = parts[i];
            if (char.IsDigit(sym[0]))
            {
                yield return sym;
            }
            else
            {
                for (int j = 0; j < sym.Length; j++)
                {
                    if (sym[j] == '+' || sym[j] == '-' || sym[j] == '*' || sym[j] == '/')
                    {
                        yield return sym[j].ToString();
                    }
                    else
                    {
                        yield return sym.Substring(j);
                        j = sym.Length;
                    }
                }
            }
        }
    }

    public static void Main(string[] args)
    {
        string line = Console.ReadLine();
        Console.WriteLine(new Solution().getResult(line));
    }
}
