#include "esp_camera.h"

// ============================================
// PIN DEFINITIONS
// ============================================
#define BUTTON_PIN 13   // Doorbell button
#define BUZZER_PIN 14   // Passive buzzer

// Camera pins (AI-Thinker ESP32-CAM)
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

// ============================================
// DOORBELL SOUND
// ============================================
void playDingDong() {
  // "Ding"
  tone(BUZZER_PIN, 800, 200);
  delay(250);
  // "Dong"
  tone(BUZZER_PIN, 600, 300);
  delay(350);
  noTone(BUZZER_PIN);
}

// ============================================
// BUTTON INTERRUPT
// ============================================
void IRAM_ATTR buttonPressed() {
  playDingDong();
}

// ============================================
// SETUP
// ============================================
void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\n================================");
  Serial.println("ESP32-CAM DOORBELL");
  Serial.println("================================\n");

  // Setup pins
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  digitalWrite(BUZZER_PIN, LOW);
  
  Serial.println("✓ Pins configured");
  
  // Attach button interrupt
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonPressed, FALLING);
  Serial.println("✓ Button ready");

  // Camera configuration
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_VGA;
  config.jpeg_quality = 12;
  config.fb_count = 1;

  // Initialize camera
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("✗ Camera failed: 0x%x\n", err);
    Serial.println("Camera not needed for doorbell to work!");
  } else {
    Serial.println("✓ Camera ready");
  }

  Serial.println("\n================================");
  Serial.println("🔔 DOORBELL READY!");
  Serial.println("================================");
  Serial.println("Press the button to ring!");
  Serial.println("================================\n");

  // Welcome chime
  playDingDong();
}

// ============================================
// LOOP
// ============================================
void loop() {
  // Nothing to do - button interrupt handles everything!
  delay(100);
}
