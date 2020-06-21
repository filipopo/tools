// Password strength checking program with examples for C#, C++, C
// https://en.wikipedia.org/wiki/Truth_table#Applications_of_truth_tables_in_digital_electronics
#ifdef __cplusplus
#include <iostream>
#include <fstream>
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

char modifier(char ch) {
   if (ch >= 'a' && ch <= 'z')
      return toupper(ch);
   else if (ch >= 'A' && ch <= 'Z')
      return tolower(ch);

   if (ch == '0')
      return '1';
   else
      return '0';

   return ch;
}

#ifdef __cplusplus
void special(string pass) {
   int len = pass.length();
#else
void special(char *pass) {
   int len = strlen(pass);
#endif
   int pos = 0;
   while(pos < len && pass[pos] != '|') {
      pass[pos] = pass[pos + 1];
      pos++;
   }

   if (pass[pos] <= len) {
      for (int i = pos - 1;i < len;i++)
         pass[pos] = pass[pos + 1];
   } else {
      #ifdef __cplusplus
      pass.erase(len - 1);
      #else
      pass[len - 1] = '\0';
      #endif
   }
}

int num = 0;
#ifdef __cplusplus
void loopy(string pass, int pos) {
   for (int i = pos; i < pass.length(); i++) {
#else
void loopy(char *pass, int pos) {
   for (int i = pos; i < strlen(pass); i++) {
#endif
      pos++;
      loopy(pass, pos);

      if (pass[i] != '|')
         pass[i] = modifier(pass[i]);
      else
         special(pass);
   }

   #ifdef __cplusplus
   cout << pass << endl;
   myfile << pass << endl;
   #else
   printf("%s\n", pass);
   fprintf(myfile, "%s\n", pass);
   #endif
   num++;
}

#ifdef __cplusplus
void find(string pass) {
   myfile.open("comb.txt");
#else
void find(char *pass) {
   myfile = fopen("comb.txt", "w+");
#endif
   loopy(pass, 0);
   #ifdef __cplusplus
   cout << num << " Combinations" << endl;
   myfile.close();
   #else
   fclose(myfile);
   printf("%d Combinations\n", num);
   #endif
}

int main() {
   #ifdef __cplusplus
   string mode;
   cout << "Pass or table generator?:" << endl;
   cin >> mode;
   if (mode == "table") {
      cout << "Numbers: ";
   #else
   char mode[6];
   printf("Pass or table generator?:\n");
   scanf("%s", &mode);
   if (!strcmp(mode, "table")) {
      printf("Numbers: ");
   #endif
      int n;
      #ifdef __cplusplus
      cin >> n;
      string s = "0";
      #else
      scanf("%d", &n);
      char s[n + 1];
      strcpy(s, "0");
      #endif

      for(;n > 1;n--)
      #ifdef __cplusplus
         s += '0';
      #else
         strcat(s, "0");
      #endif

      find(s);
   } else {
      #ifdef __cplusplus
      string pass;
      cout << "Input: ";
      cin >> pass;
      #else
      char pass[10];
      printf("Input: ");
      scanf("%s", &pass);
      #endif
      find(pass);
   }
}
