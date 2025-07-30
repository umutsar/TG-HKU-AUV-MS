#include "ALACAKART.h"
ALACA_KART Veri_Kontrol;

void setup()
{
  Serial.begin(9600);
  Serial1.begin(57600);
  Veri_Kontrol.Servo_1_begin();
  Veri_Kontrol.Servo_5_begin();
  Veri_Kontrol.Servo_3_begin();
  Veri_Kontrol.Servo_4_begin();

  Serial.println("Servo kontrol başlatıldı. Lütfen 1000 - 2000 arası bir değer girin:");
}

void loop()
{
  if (Serial.available() > 0)
  {
    String input = Serial.readStringUntil('\n');
    input.trim();
    int pwmValue = input.toInt();

    if (pwmValue >= 1000 && pwmValue <= 2000)
    {
      Veri_Kontrol.Servo_1(pwmValue);
      Veri_Kontrol.Servo_5(pwmValue);
      Veri_Kontrol.Servo_3(pwmValue);
      Veri_Kontrol.Servo_4(pwmValue);
      Serial.print("Servo 1 pozisyonu: ");
      Serial.println(pwmValue);
    }
    else
    {
      Serial.println("⚠️ Hatalı giriş! Lütfen 1000 ile 2000 arasında bir sayı girin.");
    }
  }
}
