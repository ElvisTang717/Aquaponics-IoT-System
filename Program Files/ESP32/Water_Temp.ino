#include <OneWire.h>
#include <DallasTemperature.h>

const int oneWireBus = 1;     

OneWire oneWire(oneWireBus);
DallasTemperature DS18B20(&oneWire);

short gn=0, gi=0;
float gx[1000];

void setup_Wtemp() {
  DS18B20.begin();
  for(int i=0;i<1000;i++){ gx[i]=0; }
}

void loop_Wtemp() {
  DS18B20.requestTemperatures(); 
  float temperatureC = DS18B20.getTempCByIndex(0);
  Serial.println(temperatureC);
  gx[gi++] = temperatureC;
  if(gi>999){ gi=0; }
  if(gn<1000){ gn++; }
  }
 
 String get_Wtemp(void){
  String ss="";
  int i, n;

  if(gn!=1000){ n=0; }else{ n = gi; }
  for(i=0;i<(gn-1);i++){
    ss += String(gx[n++])+',';
    if(n>999){ n=0; }
  }
  ss += String(gx[n++]);
  return ss;
}
