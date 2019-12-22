//Password strength checking program with examples for C#,C++,C
//https://en.wikipedia.org/wiki/Truth_table#Applications_of_truth_tables_in_digital_electronics

using System;
using System.IO;
using System.Text;

namespace code{
   abstract class redpill{
      StreamWriter myfile = new StreamWriter("comb.txt");
      protected abstract char modifier(char ch);
      protected virtual void special(string pass){}

      int num=0;
      void loopy(string pass, int pos){
         for (int i = pos; i < pass.Length; i++){
            if ( pos < pass.Length ){
               pos++;
               loopy(pass,pos);
            }

            if (pass[i] != '|'){
               StringBuilder sb = new StringBuilder(pass);
               sb[i]=modifier(pass[i]);
               pass=sb.ToString();
            }
            else
               special(pass);
         }
         Console.WriteLine(pass);
         myfile.WriteLine(pass);
         num++;
      }

      public void find(string pass){
         loopy(pass,0);
         myfile.Close();
         Console.WriteLine(num+" Combinations");
      }
   }

   class tablica : redpill{
      public tablica(int n){
         string s = "0";
         for(;n>1;n--)
            s+='0';
         find(s);
      }

      protected override char modifier(char ch){
         if (ch == '0')
            return '1';
         else
            return '0';
      }
   }

   class kotezvao : redpill{
      protected override char modifier(char ch){
         if (ch >= 'a' && ch <= 'z')
            return Char.ToUpper(ch);
         else if (ch >= 'A' && ch <= 'Z')
            return Char.ToLower(ch);

         return ch;
      }

      protected override void special(string pass){
         StringBuilder sb = new StringBuilder(pass);
         int pos=0;
         bool loop = true;
         while(loop){
            if (pos >= pass.Length-2 || pass[pos] == '|')
               loop = false;
            sb[pos]=sb[pos+1];
            pos++;
         }
         pass=sb.ToString();
      }
   }

   class program{
      static void Main(){
         Console.WriteLine("Pass or table generator?:");
         if (Console.ReadLine() == "table"){
            Console.Write("Numbers: ");
            tablica ae = new tablica(Convert.ToInt32(Console.ReadLine()));
         }
         else{
            Console.Write("Input: ");
            kotezvao ae = new kotezvao();
            ae.find((Console.ReadLine()));
         }
      }
   }
}
