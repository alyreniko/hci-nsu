// https://wokwi.com/projects/442784854235542529
// Необходимо организовать последовательное
// включение и выключение светодиодов так,
// чтобы перебирались все возможные комбинации
// их состояний (от 000 до 111 в двоичной системе).

void setup() {
    Serial.begin(9600);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
}

void loop() {
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 1; k++) { // младший бит
                digitalWrite(7, k);
                digitalWrite(6, j);
                digitalWrite(5, i);
                delay(1000);
            }
        }
    }
}
