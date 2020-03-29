using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public string GetResult(Role[] roles, Instruction[] instructions) 
    {
        int index = 0;
        foreach (var instruction in instructions) 
        {
            int dir = 1;
            if ((roles[index].Direction == 0 && instruction.Direction == 0)
                || (roles[index].Direction == 1 && instruction.Direction == 1))
            {
                dir = -1;
            }

            index = ((index + dir * instruction.Count) % roles.Length  + roles.Length) % roles.Length;
        }

        return roles[index].Name;
    }

    public static void Main(string[] args)
    {
        int m, n;
        var parts = Console.ReadLine().Split(' ');
        m = Convert.ToInt32(parts[0]);
        n = Convert.ToInt32(parts[1]);

        var roles = new Role[m];
        for (int i = 0; i < m; i++)
        {
            parts = Console.ReadLine().Split(' ', 2);
            roles[i] = new Role
            {
                Name = parts[1],
                Direction = Convert.ToInt32(parts[0])
            };
        }

        var instructions = new Instruction[n];
        for (int i = 0; i < n; i++) 
        {
            parts = Console.ReadLine().Split(' ', 2);
            instructions[i] = new Instruction
            {
                Count = Convert.ToInt32(parts[1]),
                Direction = Convert.ToInt32(parts[0])
            };
        }

        var solution = new Solution();
        System.Console.WriteLine(solution.GetResult(roles, instructions));
    }
}

public class Role
{
    public string Name { get; set; }

    public int Direction { get; set; }
}

public class Instruction
{
    public int Count { get; set; }

    public int Direction { get; set; }
}
