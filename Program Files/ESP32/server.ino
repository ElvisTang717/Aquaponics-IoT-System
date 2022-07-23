#include <WebServer.h>

WebServer server(80);

void setup_server() {

  server.on("/Wtemp", handleWtemp);
  server.on("/Wlevel", handleWlevel);
  server.on("/TDS", handleTDS);
  server.on("/Moist", handleMoist);
  server.on("/Light", handleLight);
  server.onNotFound(handle_NotFound);

  server.enableCORS();
  server.begin();
}

void loop_server(){
  server.handleClient();
}

void handleWtemp() {
 String data = get_Wtemp();
 server.send(200, "text/plain", data);
 Serial.println(data);
}

void handleWlevel() {
 String data = get_Wlevel();
 server.send(200, "text/plain", data);
 Serial.println(data);
}

void handleTDS() {
 String data = get_TDS();
 server.send(200, "text/plain", data);
 Serial.println(data);
}

void handleMoist() {
 String data = get_Moist();
 server.send(200, "text/plain", data);
 Serial.println(data);
}

void handleLight() {
 String data = get_Light();
 server.send(200, "text/plain", data);
 Serial.println(data);
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}
