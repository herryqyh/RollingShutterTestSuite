#define LED_R   3
#define LED_G   4
#define LED_B   5
#define sw_R 6
#define sw_G 7
#define sw_B 8
#define RST 9
#define BaseFreq1 500 //Green
#define BaseFreq2 2000 //Blue
#define BaseFreq3 8000 //Red


hw_timer_t *timer1 = NULL;
hw_timer_t *timer2 = NULL;
hw_timer_t *timer3 = NULL;
int color = 0;
bool is_set = false;


// 定时器中断处理函数
void timer_interrupt_R() {
  digitalWrite(LED_R, !digitalRead(LED_R));
}
void timer_interrupt_G() {
  digitalWrite(LED_G, !digitalRead(LED_G));
}
void timer_interrupt_B() {
  digitalWrite(LED_B, !digitalRead(LED_B));
}


void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  pinMode(sw_R, INPUT_PULLUP);
  pinMode(sw_G, INPUT_PULLUP);
  pinMode(sw_B, INPUT_PULLUP);

  // 初始化定时器
  timer1 = timerBegin(0, 80, true);

  Serial.begin(115200);
  digitalWrite(LED_R, 1);
  digitalWrite(LED_G, 1);
  digitalWrite(LED_B, 1);
  delay(1000);

}

void loop() {
  if (!digitalRead(sw_R) && !is_set) {
    delay(100);
    if (!digitalRead(sw_R) && !is_set) {
      timerAttachInterrupt(timer1, &timer_interrupt_R, true);
      timerAlarmWrite(timer1, 1000000 / BaseFreq1, true);
      timerAlarmEnable(timer1);
      Serial.println("R_connected");
      is_set = true;
    }
  }
  if (!digitalRead(sw_G) && !is_set) {
    delay(100);
    if (!digitalRead(sw_G) && !is_set) {

      timerAttachInterrupt(timer1, &timer_interrupt_G, true);
      timerAlarmWrite(timer1, 1000000 / BaseFreq2, true);
      timerAlarmEnable(timer1);
      Serial.println("G_connected");
      is_set = true;
    }
  }
  if (!digitalRead(sw_B) && !is_set) {
    delay(100);
    if (!digitalRead(sw_B) && !is_set) {

      timerAttachInterrupt(timer1, &timer_interrupt_B, true);
      timerAlarmWrite(timer1, 1000000 / BaseFreq3, true);
      timerAlarmEnable(timer1);
      Serial.println("B_connected");
      is_set = true;
    }
  }
}
