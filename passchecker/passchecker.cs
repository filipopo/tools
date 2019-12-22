//Password strength checking program with examples for C#,C++,C
//https://en.wikipedia.org/wiki/Truth_table#Applications_of_truth_tables_in_digital_electronics

using System;
using System.IO;
using System.Text;

namespace code{
   abstract class redpill{
      StreamWriter myfile = new StreamWriter("comb.txt");
      protected abstract char modifier(char ch);
      protected virtual void special(string pass){
      }

      int num=0;
      void loopy(string pass, int pos){
         for (int i = pos; i > 0; i--){
            if ( pos > 0 ){
               pos--;
               loopy(pass,pos);
            }

            if (pass[pos] != '|'){
               StringBuilder sb = new StringBuilder(pass);
               sb[pos]=modifier(pass[pos]);
               pass=sb.ToString();
            }
            else
               special(pass);
         }
         Console.WriteLine(pass);
         myfile.WriteLine(pass);
         num++;
      }

      protected void find(string pass){
         loopy(pass,pass.Length);
         myfile.Close();
         Console.WriteLine(num+" Combinations");
      }
   }

   class tablica : redpill{
      protected override char modifier(char ch){
         if (ch == '0')
            return '1';
         else
            return '0';
      }

      public void find(int n){
         string s = "0";
         for (int i=1;i<n;i++)
            s+='0';
         find(s);
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
         int len = pass.Length;
         while(pos < len && pass[pos] != '|'){
            sb[pos]=sb[pos+1];
            pos++;
         }
         for (int i=pos-1;i<len;i++)
            sb[i]=sb[i+1];
         pass=sb.ToString();
      }
   }

   class program{
      static void Main(){
         tablica ae = new tablica();
         Console.Write("Input: ");
         ae.find(Convert.ToInt32(Console.ReadLine()));
      }
   }
}
