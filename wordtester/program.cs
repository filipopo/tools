// example input: anavolimilovana anavolimilovaan
// See https://aka.ms/new-console-template for more information
// using System;
// using System.Collections.Generic;

namespace Program {
  class tester {
    private IDictionary<char, int> encode(string s) {
      IDictionary<char, int> d = new Dictionary<char, int>();

      foreach (char c in s) {
        if (d.ContainsKey(c))
          d[c]++;
            else
          d.Add(c, 1);
      }

      return d;
    }

    public bool anagram(string s1, string s2) {
      IDictionary<char, int> d1 = encode(s1);
      IDictionary<char, int> d2 = encode(s2);

      foreach(KeyValuePair<char, int> pair in d1) {
        if (!d2.ContainsKey(pair.Key) || d2[pair.Key] != pair.Value)
          return false;
      }

      return true;
    }

    public bool palindrome(string s) {
      for (int i = 0; i < s.Length / 2; i++) {
        if (s[i] != s[s.Length -1 -i])
          return false;
      }

      return true;
    }
  }

  internal class Program {
    static void Main(string[] args) {
      tester t = new tester();

      Console.WriteLine("Enter a string:");
      string s1 = Console.ReadLine();

      if (t.palindrome(s1))
        Console.WriteLine("\"{0}\" is a palindrome", s1);

      Console.WriteLine("Enter a second string:");
      string s2 = Console.ReadLine();

      if (t.anagram(s1, s2))
        Console.WriteLine("\"{0}\" is an anagram to \"{1}\"", s1, s2);
    }
  }
}
