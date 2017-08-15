const int BLED = 9;
const int GLED = 10;
const int RLED = 11;
const int BUTTON = 2;

boolean lastButton = LOW;
boolean currentButton = LOW;
int ledMode = 0;

void setup() {
  pinMode(BLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

boolean debounce(boolean last){
  boolean current = digitalRead(BUTTON);
  if (last != current) {
    delay(5);
    current = digitalRead(BUTTON);
    return current;
  }
}

void setColorsD(boolean r, boolean g, boolean b){
  digitalWrite(RLED, r);
  digitalWrite(GLED, g);
  digitalWrite(BLED, b);
}

void setColorsA(int r, int g, int b){
  analogWrite(RLED, r);
  analogWrite(GLED, g);
  analogWrite(BLED, b);
}

void setMode(int mode){
  if(mode == 1) {
    setColorsD(HIGH, LOW, LOW);
  } else if (mode == 2){
    setColorsD(LOW, HIGH, LOW);
  } else if (mode == 3){
    setColorsD(LOW, LOW, HIGH);
  } else if (mode == 4){
    setColorsA(127, 0, 127);
  } else if (mode == 5){
    setColorsA(0, 127, 127);
  } else if (mode == 6){
    setColorsA(127, 127, 0);
  } else if (mode == 7){
    setColorsA(85, 85, 85);
  } else {
    setColorsD(LOW, LOW, LOW);
  }
}

void loop() {
  currentButton = debounce(BUTTON);
  if(lastButton == LOW && currentButton == HIGH) {
    ledMode++;
  }
  lastButton = currentButton;

  if (ledMode == 8){
    ledMode = 0;
  }
  setMode(ledMode);
}
