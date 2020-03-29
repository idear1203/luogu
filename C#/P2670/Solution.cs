using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public char[,] GetResult(char[,] board, int m, int n) 
    {
        var result = new char[m, n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[i, j] = GetBombNum(board, i, j, m, n);
            }
        }

        return result;
    }

    private char GetBombNum(char[,] board, int row, int col, int m, int n) 
    {
        char target = board[row, col];
        if (board[row, col] == '*')
        {
            return '*';
        }
        else
        {
            var dirs = new int[,] { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };
            int count = 0;
            for (int i = 0; i < dirs.GetLength(0); i++)
            {
                int x = row + dirs[i, 0];
                int y = col + dirs[i, 1];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x, y] == '*')
                {
                    count ++;
                }
            }
            
            return (char)('0' + count);
        }
    }

    public static void Main(string[] args)
    {
        string line;
        line = Console.ReadLine();
        var nums = line.Split(' ');
        int m = Convert.ToInt32(nums[0]);
        int n = Convert.ToInt32(nums[1]);
        var lines = new List<string>();
        var board = new char[m, n];
        for (int i = 0; i < m; i++)
        {
            line = Console.ReadLine();
            for (int j = 0; j < n; j++)
            {
                board[i, j] = line[j];
            }
        }
        
        var solution = new Solution();
        var outputs = solution.GetResult(board, m, n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                System.Console.Write(outputs[i, j]);
            }

            System.Console.WriteLine();
        }
    }
}