void setup() {
  Serial.begin(115200);
  setup_wifi_ap();
  setup_wifi_sta();
  setup_Wtemp();
  setup_Wlevel();
  setup_TDS();
  setup_Moist();
  setup_Light();  
  setup_server();
  Serial.println("HTTP server started");
}

void loop() {
  loop_Wtemp();
  loop_Wlevel();
  loop_TDS();
  loop_Moist();
  loop_Light();
  loop_server();
  delay(200);
}
