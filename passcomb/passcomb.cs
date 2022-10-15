// Password strengthening program making use of truth table traversing
// https://en.wikipedia.org/wiki/Truth_table#Applications_of_truth_tables_in_digital_electronics

using System;
using System.IO;
using System.Text;
using System.Collections.Generic;

namespace code {
  abstract class redpill {
    StreamWriter myfile = new StreamWriter("comb.txt");
    protected abstract char modifier(char ch);
    protected virtual bool print(string s) {return true;}

    int num = 0;

    void loopy(string s, int pos) {
      StringBuilder sb = new StringBuilder(s);
      for (int i = pos; i < s.Length; i++) {
        pos++;
        loopy(sb.ToString(), pos);
        sb[i] = modifier(s[i]);
      }

      if (print(sb.ToString())) {
        Console.WriteLine(sb.ToString());
        myfile.WriteLine(sb.ToString());
        num++;
      }
    }

    protected void find(string s) {
      loopy(s, 0);
      myfile.Close();
      Console.WriteLine(num + " Combinations");
    }
  }

  class tablica : redpill {
    public tablica(int n) {
      string s = "0";
      for(; n > 1; n--)
        s += '0';

      find(s);
    }

    protected override char modifier(char ch) {
      if (ch == '0')
        return '1';
      else
        return '0';
    }
  }

  class kotezvao : redpill {
    public kotezvao(string s) {
      find(s);
    }

    HashSet<string> h = new HashSet<string>();

    protected override bool print(string s) {
      if (h.Contains(s))
        return false;

      h.Add(s);
      return true;
    }

    protected override char modifier(char ch) {
      if (ch >= 'a' && ch <= 'z')
        return Char.ToUpper(ch);
      else if (ch >= 'A' && ch <= 'Z')
        return Char.ToLower(ch);

      return ch;
    }
  }

  class program {
    static void Main() {
      Console.WriteLine("Pass or table generator?:");
      if (Console.ReadLine() == "table") {
        Console.Write("Numbers: ");
        int num;
        if (int.TryParse(Console.ReadLine(), out num))
          new tablica(num);
      } else {
        Console.Write("Input: ");
        #pragma warning disable CS8604
        new kotezvao(Console.ReadLine());
      }
    }
  }
}
