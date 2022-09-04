#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <string.h>
#include <unistd.h>
#endif

int main() {
  char cc[34];
  FILE *p;
  int ch;

  while (1) {
    time_t now = time(0);
    struct tm* timeinfo = localtime(&now);

    sprintf(cc, "node timeconvertor.js 12 %d:%d:%d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    p = popen(cc, "r");
    
    if(p == NULL) {
      printf("Unable to open process");
      return(1);
    }

    strcpy(cc, "");
    while((ch=fgetc(p)) != EOF)
      strncat(cc, &ch, 1);
/*
    char s[6];
    hour -= 4;
    if (hour < 0) {
      hour = abs(hour);
      strcpy(s, "since");
    } else
      strcpy(s, "until");

    char h[3];
    two(h, hour);
    char m[3];
    two(m, abs(timeinfo->tm_min - 20));

    printf("%s %s 4:20\n", t, s);
*/
    pclose(p);
    #ifdef _WIN32
    Sleep(60000);
    #else
    sleep(60);
    #endif
  }
}
