#include <stdio.h>
#include <stdlib.h>

void java(char *oblast) {
  FILE *myfile  = fopen("program.java", "w+");
  fprintf(myfile, "public class program{\n  public static void main(String[] args) {\n    %s\n  }\n}\n", oblast);
  fclose(myfile);
  system("javac program.java");
  system("java program");
  printf("public class program{\n  public static void main(String[] args) {\n    %s\n  }\n}\n\n", oblast);
}

void c(char *oblast) {
  FILE *myfile  = fopen("program.c", "w+");
  fprintf(myfile, "#include <stdio.h>\n\nint main() {\n  %s\n}\n", oblast);
  fclose(myfile);
  system("gcc program.c -o program"); // http://www.codebind.com/cprogramming/install-mingw-windows-10-gcc/
  printf("#include <stdio.h>\n\nint main() {\n  %s\n}\n\n", oblast);
  system("./program");
}

void cpp(char *oblast) {
  FILE *myfile  = fopen("program.cpp", "w+");
  fprintf(myfile, "#include <iostream>\n\nint main() {\n  %s\n}\n", oblast);
  fclose(myfile);
  system("g++ program.cpp -o program"); // http://www.codebind.com/cprogramming/install-mingw-windows-10-gcc/
  printf("#include <iostream>\n\nint main() {\n  %s\n}\n\n", oblast);
  system("./program");
}

void python(char *oblast) {
  FILE *myfile  = fopen("program.py", "w+");
  fprintf(myfile, "%s\n", oblast);
  fclose(myfile);
  printf("%s\n\n", oblast);
  system("python program.py");
}

void cs(char *oblast) {
  FILE *myfile  = fopen(".cs", "w+");
  fprintf(myfile, "using System;\n\nnamespace egg{\n  class program{\n    static void Main() {\n      %s\n    }\n  }\n}\n\n", oblast);
  fclose(myfile);
  printf("using System;\n\nnamespace egg{\n  class program{\n    static void Main() {\n      %s\n    }\n  }\n}\n\n", oblast);
  system("dotnet new console && dotnet run");
}

void node(char *oblast) {
  FILE *myfile  = fopen("program.js", "w+");
  fprintf(myfile, "%s\n", oblast);
  fclose(myfile);
  printf("%s\n\n", oblast);
  system("node program.js");
}

void sql(char *oblast) {
  FILE *myfile  = fopen("program.sql", "w+");
  fprintf(myfile, "%s\n", oblast);
  fclose(myfile);
  if (system("mysql") == 32512)
    return;
  printf("%s\n\n", oblast);
  system("mysql source program.sql");
}

void (*funcs[])() = {
  java,
  c,
  cpp,
  python,
  cs,
  node
};

int main(int argc, char *argv[]) {
  char *oblasti[] = { // Jezici
    "System.out.println(\"Java\");",
    "printf(\"C\\n\");",
    "std::cout << \"C++\" << std::endl;",
    "print('Python')",
    "Console.WriteLine(\"C#\");",
    "console.log('JavaScript/Node.js');",
    //"echo 'PHP'",
    "PRINT 'SQL'" // Baze podataka
  };

  int c;
  if (argc > 1)
    c = atoi(argv[0]);
  else {
    for (short i = 0; i < sizeof(oblasti) / sizeof(oblasti[0]); i++)
      printf("%d) %s\n", i, oblasti[i]);

    scanf("%d", &c);
  }

  (*funcs[c])(oblasti[c]);
}
