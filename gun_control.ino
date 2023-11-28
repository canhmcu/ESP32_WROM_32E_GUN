#include "BluetoothSerial.h"
#include<WiFi.h>
#include <WiFiUdp.h>

WiFiUDP udp;

unsigned int localPort = 60110;
unsigned int mPort = 60111;
const char*  mIP = "192.168.110.247";

const char* ssid = "XX";         //Tên mạng Wifi mà Socket server của bạn đang kết nối
const char* password = "160802160802";  //Pass mạng wifi ahihi, anh em rãnh thì share pass cho mình với.


#define LED_PWR 19
#define LED_STT 18
#define LED_DP 17
#define CTR_LASER 16 // Dieu khien Laser
#define CTR_PWR_L 32 // Dieu khien SG3525A
#define CTR_PWR_H 33 // Dieu khien mosfet 600V
#define BUTTON 34 // Hall thay bang button
int PWR_L = 25;
const int analogInPin = A6;
int sensorValue = 0;

int flag = 0;
void setup()
{
  //SerialBT.begin("GUN_Control"); //Bluetooth device name

  //  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_PWR, OUTPUT);
  pinMode(LED_STT, OUTPUT);
  pinMode(LED_DP, OUTPUT);
  pinMode(CTR_LASER, OUTPUT);
  pinMode(CTR_PWR_L, OUTPUT);
  pinMode(CTR_PWR_H, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(PWR_L, INPUT);

  digitalWrite(CTR_PWR_L, LOW);
  digitalWrite(CTR_PWR_H, LOW);
  delay(500);
  digitalWrite(CTR_PWR_L, HIGH);
  delay(500);
  // digitalWrite(LED_BUILTIN, HIGH);
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(LED_PWR, HIGH);
    delay(500);
    digitalWrite(LED_PWR, LOW);
    delay(500);
  }
  Serial.begin(115200);
  Serial.print("\nWifi connecting...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  udp.begin(localPort);
  Serial.print(F("UDP Client : "));
  Serial.println(WiFi.localIP());
  digitalWrite(19, HIGH);

  //pinMode(PWR_L, INTPUT);
}

void loop()
{
  udp.beginPacket(mIP, mPort);
  udp.print("031");
  udp.endPacket();
  delay(1000);
  /*if (SerialBT.available())
    {
    SerialBT.read()
    SerialBT.write();
    }
    sensorValue = analogRead(analogInPin);
    int buttonState = digitalRead(pushButton);*/
  if (digitalRead(BUTTON) == 1)
  {
    digitalWrite(CTR_PWR_L, LOW);
    digitalWrite(CTR_PWR_H, HIGH);
    digitalWrite(CTR_LASER, HIGH);
    digitalWrite(19, LOW);
    delay(200);
    digitalWrite(CTR_PWR_L, HIGH);
    digitalWrite(CTR_PWR_H, LOW);
    digitalWrite(CTR_LASER, LOW);
    Serial.print("\nOK");
  }
  else
  {
    digitalWrite(19, HIGH);
    Serial.print("\nNO");
  }
}
