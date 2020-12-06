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

void two(char* s, int digit) {
	char temp[4] = "0%d";
	if (digit > 9) {
		for (int i = 0; i < 3; i++)
			temp[i] = temp[i + 1];
	}
	sprintf(s, temp, digit);
}

int main() {
	while (1) {
		time_t now = time(0);
		struct tm* timeinfo = localtime(&now);

		int hour = timeinfo->tm_hour;
		char t[3] = "AM";
		if (hour > 12) {
			hour -= 12;
			t[0] = 'P';
		}

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

		printf("%s:%s %s 4:20 %s\n", h, m, s, t);
#ifdef _WIN32
		Sleep(60000);
#else
		sleep(60);
#endif
	}
}
