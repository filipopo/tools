//Password strength checking program with examples for C++,C#,C
 //https://en.wikipedia.org/wiki/Truth_table#Applications_of_truth_tables_in_digital_electronics

#if __cplusplus
#include <iostream>
#include <fstream>
#include <string>
#else
using System;
using System.IO;
#endif

#if __cplusplus
using namespace std;
ofstream myfile;
#else
namespace code{
   class program{
      StreamWriter myfile = new StreamWriter("comb.txt");
#endif

char modifier(char ch){
   if (ch >= 'a' && ch <= 'z')
      return toupper(ch);
   else if (ch >= 'A' && ch <= 'Z')
      return tolower(ch);

   return ch;
}

void special(string pass){
   int pos=0;
   int len = pass.length();
   while(pos < len && pass[pos] != '|'){
      pass[pos]=pass[pos+1];
      pos++;
   }

   if (pass[pos] <= len){
      for (int i=pos-1;i<len;i++)
         pass[pos]=pass[pos+1];
   }
   else{
      #if __cplusplus
      pass.erase(len-1);
      #else
      pass=pass.Substring(0,len-2);
      #endif
   }
   #if DEBUG
   cout << "\nSpecial:\n";
   cout << pass;
   cout << "\n:Special\n";
   #endif
}

void loopy(string pass, int pos){
   for (int i = pos; i > 0; i--){
      if ( pos > 0 ){
         #if DEBUG
         cout << "\nLoopy_for:\n";
         cout << pos << endl;
         cout << pass << endl;
         cout << "\n:Loopy_for\n";
         #endif
         pos--;
         loopy(pass,pos);
      }
      if (pass[pos] != '|')
         pass[pos]=modifier(pass[pos]);
      else
         special(pass);
      }
      #if DEBUG
      cout << "\nLoopy:\n";
      #endif
      #if __cplusplus
      cout << pass << endl;
      myfile << pass << endl;
      #else
      Console.WriteLine(pass);
      myfile.WriteLine(pass);
      #endif
      #if DEBUG
      cout << "\n:Loopy\n";
      #endif
}

#if __cplusplus
int main(){
   string pass;
   cout << "Input: ";
   cin >> pass;
   myfile.open ("comb.txt");
#else
      public static void Main(){
         Console.Write("Input: ");
         string pass = Console.ReadLine();
#endif
   loopy(pass,pass.length());
   myfile.close();
      }
#if !__cplusplus
   }
}
#endif

/*
#include <stdio.h>
#include <ctype.h>
#include <string.h>

FILE *myfile;

void special(char* pass, int *pos){

pass[len-1]='\0';

void loopy(char* pass, int pos){

printf("%s",pass);
fprintf(myfile,pass);

char pass[10];
printf("Input: ");
scanf("%s", &pass);
myfile = fopen("comb.txt", "w+");
loopy(pass,strlen(pass));
fclose(myfile);
*/
