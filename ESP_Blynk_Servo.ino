#define BLYNK_TEMPLATE_ID "TMPL24xlEodDt"
#define BLYNK_TEMPLATE_NAME "Servo"
#define BLYNK_AUTH_TOKEN "TKYuZ4IF4vhWYpGRdUs_WA99MwU-KH_-"

#ifdef ESP32
  #include <WiFi.h>
  #include <BlynkSimpleEsp32.h>
  #include <ESP32Servo.h>
  #define SERVO_PIN       13
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
  #include <BlynkSimpleEsp8266.h>
  #include <Servo.h>
  #define SERVO_PIN       D4
#else
  #error "Unsupported board! Use ESP32 or ESP8266."
#endif

#define WIFI_SSID           "2001"
#define WIFI_PASS           "19821968"

Servo myServo;

BLYNK_WRITE(V0) {
  int angle = param.asInt();  // Get value from app
  myServo.write(angle);       // Rotate servo
}

void setup() {
  Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASS);
  myServo.attach(SERVO_PIN); // Replace with your servo pin
}

void loop() {
  Blynk.run();
}
