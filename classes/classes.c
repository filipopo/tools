/*Casovi informatike i programiranja
na platformama Windows, Linux*/
//#define DEBUG
//#define mthreading
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef DEBUG
#include <time.h>
#endif
#ifdef mthreading
#include <pthread.h> //https://en.wikipedia.org/wiki/POSIX_Threads#POSIX_Threads_for_Windows
//#include <semaphore.h>  
#endif

#ifdef mthreading
const char oblasti[][38]={ //Jezici
	"System.out.println(\"Java\");",
	"cout << \"C/C++\" << endl;",
	"print('Python')",
	"Console.WriteLine(\"C#\");",
	"console.log('JavaScript/Node.js');",
	//"echo 'PHP'",
	"PRINT 'SQL'",
	"Algoritmi i strukture podataka",
	"Opsta informatika"
};

short i=0;
FILE *myfile;
char str[8];

void *javaf(void *arg) {
	myfile = fopen(strcat(str,".java"), "w+");
	fprintf(myfile,"public class P%c{\n\tpublic static void main(String[] args){\n\t\t%s\n\t}\n}\n",str[1],oblasti[i]);
	fclose(myfile);
	char cp0[14]="javac ";
	system(strcat(cp0,str));
	sprintf(str, "P%d", i);
	system(strcat(strcpy(cp0,"java "),str));
	printf("public class P%c{\n\tpublic static void main(String[] args){\n\t\t%s\n\t}\n}\n\n",str[1],oblasti[i]);
}

void *cppf(void *arg) {
	myfile = fopen(strcat(str,".cpp"), "w+");
	fprintf(myfile,"#include <iostream>\n\nusing namespace std;\n\nint main(){\n\t%s\n}\n",oblasti[i]);
	fclose(myfile);
	char cp1[16]="g++ "; //http://www.codebind.com/cprogramming/install-mingw-windows-10-gcc/
	sprintf(str, "P%d", i);
	system(strcat(strcat(strcat(strcat(cp1,str),".cpp")," -o "),str));
	strcpy(cp1,"./");
	pthread_join((pthread_t *)arg, NULL);
	system(strcat(cp1,str));
	printf("#include <iostream>\n\nusing namespace std;\n\nint main(){\n\t%s\n}\n\n",oblasti[i]);
}

void *pyf(void *arg) {
	myfile = fopen(strcat(str,".py"), "w+");
	fprintf(myfile,"%s\n",oblasti[i]);
	fclose(myfile);
	char cp2[13]="python ";
	pthread_join((pthread_t *)arg, NULL);
	system(strcat(cp2,str));
	printf("%s\n\n",oblasti[i]);
}
#endif

int main(){
	#ifdef DEBUG
	clock_t start = time(NULL);
	#endif
	#ifndef mthreading
	const char oblasti[][38]={ //Jezici
		"System.out.println(\"Java\");",
		"cout << \"C/C++\" << endl;",
		"print('Python')",
		"Console.WriteLine(\"C#\");",
		"console.log('JavaScript/Node.js');",
		//"echo 'PHP'",
		"PRINT 'SQL'",
		"Algoritmi i strukture podataka",
		"Opsta informatika"
	};

	for (short i=0; i<sizeof(oblasti)/sizeof(oblasti[0]); i++){
		FILE *myfile;
		char str[8];
	#else
	pthread_t t1,t2,t3;
	for (i; i<sizeof(oblasti)/sizeof(oblasti[0]); i++){
	#endif
		sprintf(str, "P%d", i);
		switch (i){
			case 0:
				#ifdef mthreading
				pthread_create(&t1, NULL, javaf, NULL);
				#else
				myfile = fopen(strcat(str,".java"), "w+");
				fprintf(myfile,"public class P%c{\n\tpublic static void main(String[] args){\n\t\t%s\n\t}\n}\n",str[1],oblasti[i]);
				fclose(myfile);
				char cp0[14]="javac ";
				system(strcat(cp0,str));
				sprintf(str, "P%d", i);
				system(strcat(strcpy(cp0,"java "),str));
				printf("public class P%c{\n\tpublic static void main(String[] args){\n\t\t%s\n\t}\n}\n\n",str[1],oblasti[i]);
				#endif
				break;
			case 1:
				#ifdef mthreading
				pthread_create(&t2, NULL, cppf, (void *)&t1);
				#else
				myfile = fopen(strcat(str,".cpp"), "w+");
				fprintf(myfile,"#include <iostream>\n\nusing namespace std;\n\nint main(){\n\t%s\n}\n",oblasti[i]);
				fclose(myfile);
				char cp1[16]="g++ "; //http://www.codebind.com/cprogramming/install-mingw-windows-10-gcc/
				sprintf(str, "P%d", i);
				system(strcat(strcat(strcat(strcat(cp1,str),".cpp")," -o "),str));
				strcpy(cp1,"./");
				system(strcat(cp1,str));
				printf("#include <iostream>\n\nusing namespace std;\n\nint main(){\n\t%s\n}\n\n",oblasti[i]);
				#endif
				break;
			case 2:
				#ifdef mthreading
				pthread_create(&t3, NULL, pyf, (void *)&t2);
				#else
				myfile = fopen(strcat(str,".py"), "w+");
				fprintf(myfile,"%s\n",oblasti[i]);
				fclose(myfile);
				char cp2[13]="python ";
				system(strcat(cp2,str));
				printf("%s\n\n",oblasti[i]);
				#endif
				break;
			case 3:
				myfile = fopen(strcat(str,".cs"), "w+");
				fprintf(myfile,"using System;\n\nnamespace egg{\n\tclass program{\n\t\tstatic void Main(){\n\t\t\t%s\n\t\t}\n\t}\n}\n\n",oblasti[i]);
				fclose(myfile);
				system("dotnet run");
				printf("using System;\n\nnamespace egg{\n\tclass program{\n\t\tstatic void Main(){\n\t\t\t%s\n\t\t}\n\t}\n}\n\n",oblasti[i]);
				break;
			case 4:
				myfile = fopen(strcat(str,".js"), "w+");
				fprintf(myfile,"%s\n",oblasti[i]);
				fclose(myfile);
				char cp4[11]="node ";
				system(strcat(cp4,str));
				printf("%s\n\n",oblasti[i]);
				break;
			/*case 5:
				myfile = fopen(strcat(str,".sql"), "w+");
				fprintf(myfile,"%s\n",oblasti[i]);
				fclose(myfile);
				if (system("mysql") == 32512)
					break;
				char cp5[19]="mysql source ";
				system(strcat(cp5,str));
				printf("%s\n\n",oblasti[i]);
				break;*/
			default:
				myfile = fopen(strcat(str,".txt"), "w+");
				printf("%s\n",oblasti[i]);
				fprintf(myfile,"%s\n",oblasti[i]);
				fclose(myfile);
				#ifdef _WIN32
				char command[15]="notepad ";
				#else
				char command[15]="$EDITOR "; //nano should be the default, GUI's are for plebs
				#endif
				//system(strcat(command,str));
				break;
		}
	}
	printf("\n( ͡°( ͡° ͜ʖ( ͡° ͜ʖ ͡°) ͜ʖ ͡°) ͡°) https://drive.google.com/file/d/1xJRzyLxt0KIc-_a9npKJUW8vWbrVea48/view?usp=sharing\n");
	#ifdef DEBUG
	clock_t end = time(NULL);
	printf("Execution time:%d seconds\n",end-start);
	#endif
}

/*softversko servisiranje, hardverska nadogradnja
3d designing, photoshop, after effects...
front-end for websites...
some other shit too like making apps*/
