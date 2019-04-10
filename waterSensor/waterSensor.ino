const int WATER = A0;
int value = 0;
unsigned long startTime = 0;

void deepSleep();

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(2000);
  startTime = millis();
}

void loop() {
  value = analogRead(WATER);
  Serial.println(value);
  delay(400);
  if ((millis() - startTime) > 2000) {
    Serial.println("0");
    deepSleep(60);
  }
}

void deepSleep(long time) {
  ESP.deepSleep(time * 1000000);
}
