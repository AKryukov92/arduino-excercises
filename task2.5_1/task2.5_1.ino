//Две лампочки, загорающиеся по очереди
const int LED1=9;
const int LED2=8;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, HIGH);
    delay(500);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    delay(500);
}
