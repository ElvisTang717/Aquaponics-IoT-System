#include <WiFi.h>


void setup_wifi_sta() {
  const char* ssid     = "ORBI76";
  const char* password = "bravevase454";

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}
