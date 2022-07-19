#define __pin 3
#define __time 500

void setup() {
  Serial.begin(9600);
  pinMode(__pin, OUTPUT);
}

void delayf(short time) {
  digitalWrite(__pin, HIGH);
  delay(time);
  digitalWrite(__pin, LOW);
  delay(__time);
}

void send(char c) {
  switch (c) {
    case '/': delay(__time * 7); break;
    case '.': delayf(__time); break;
    case '-': delayf(__time * 3); break;
  }
}

void loop() {
  char s[]="-.-- --- ..- .----. .-. . / ... --- / ... -- .- .-. -";
  for (uint8_t i=0; i < sizeof(s) - 1; i++)
    send(s[i]);
  send('/');
}
