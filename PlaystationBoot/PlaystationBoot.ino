// 203Kb SEGA boot screen with sound.

#include <M5Stack.h>
#include "PS1Img1.h"
#include "PS1Img2.h"
#include "PS1Startup20Hz.h"

extern const unsigned char PS1Startup20Hz[];
extern const uint16_t PS1Img1[], PS1Img2[];

void playstationBoot(){
    xTaskCreatePinnedToCore(logoTask, "LogoTask", 4096, NULL, 2, NULL, 0);
    playAudio();
}

void playAudio(void) {
  uint32_t length = strlen((char*)PS1Startup20Hz); // 267,795 bytes
  for (int i = 0; i < length; i++) {
    dacWrite(SPEAKER_PIN, PS1Startup20Hz[i] >> 2);
    delayMicroseconds(50);
  }
  for (int i = 32; i >= 0; i--) {
    dacWrite(SPEAKER_PIN, i);
    delay(2);
  }
}

void logoTask(void *arg) {
  static uint8_t brightness, pre_brightness;
  M5.Lcd.setBrightness(0);
  M5.Lcd.clear(TFT_WHITE);
  M5.Lcd.drawBitmap(0, 0, 320, 240, (uint16_t *)PS1Img1);
  for (int i = 0; i < 255; i += 5) {
    delay(60);
    M5.Lcd.setBrightness(i);
  }
  delay(3700);
  for (int i = 255; i > 0; i -=5 ) {
    delay(25);
    M5.Lcd.setBrightness(i);
  }
  M5.Lcd.drawBitmap(0, 0, 320, 240, (uint16_t *)PS1Img2);
  for (int i = 0; i < 255; i += 5) {
    delay(25);
    M5.Lcd.setBrightness(i);
  }
  delay(4000);
  for (int i = 255; i > 0; i -= 5) {
    delay(25);
    M5.Lcd.setBrightness(i);
  }
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setBrightness(255);
  vTaskDelete(NULL);
}

void setup()
{
  M5.begin();
  M5.Power.begin();
  playstationBoot();
}

void loop() {

}
