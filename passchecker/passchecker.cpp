//Password strength checking program with examples for C#,C++,C
//https://en.wikipedia.org/wiki/Truth_table#Applications_of_truth_tables_in_digital_electronics

#ifdef __cplusplus
#include <iostream>
#include <fstream>
#include <string>
#else
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#endif

#ifdef __cplusplus
using namespace std;
ofstream myfile;
#else
FILE *myfile;
#endif

char modifier(char ch){
   if (ch >= 'a' && ch <= 'z')
      return toupper(ch);
   else if (ch >= 'A' && ch <= 'Z')
      return tolower(ch);

   return ch;
}

#ifdef __cplusplus
void special(string pass){
#else
void special(char* pass){
#endif
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
      #ifdef __cplusplus
      pass.erase(len-1);
      #else
      pass[len-1]='\0';
      #endif
   }
}

#ifdef __cplusplus
void loopy(string pass, int pos){
#else
void loopy(char* pass, int pos){
#endif
   for (int i = pos; i > 0; i--){
      if ( pos > 0 ){
         pos--;
         loopy(pass,pos);
      }
      if (pass[pos] != '|')
         pass[pos]=modifier(pass[pos]);
      else
         special(pass);
      }
      #ifdef __cplusplus
      cout << pass << endl;
      myfile << pass << endl;
      #else
      printf("%s",pass);
      fprintf(myfile,pass);
      #endif
}

#ifdef __cplusplus
int main(){
   string pass;
   cout << "Input: ";
   cin >> pass;
   myfile.open ("comb.txt");
   loopy(pass,pass.length());
   myfile.close();
#else
char pass[10];
printf("Input: ");
scanf("%s", &pass);
myfile = fopen("comb.txt", "w+");
loopy(pass,strlen(pass));
fclose(myfile);
#endif
}
