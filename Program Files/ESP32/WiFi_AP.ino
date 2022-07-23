#include <WiFi.h>


void setup_wifi_ap() {
  const char* ssid = "ESP32";
  const char* password = "12345678";
  
  IPAddress local_ip(192,168,1,1);
  IPAddress gateway(192,168,1,1);
  IPAddress subnet(255,255,255,0);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
}
