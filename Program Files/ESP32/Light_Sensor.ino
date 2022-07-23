
int photocellPin = 8; // connect the anallog pin 2 on photocell
int photocellVal = 0; // photocell value
int minLight = 2500;  // light intensity minimum
int ledPin = 9;
int ledState = 0;

short ln=0, li=0;
int lx[1000];

void setup_Light() {
  pinMode(ledPin, OUTPUT);
  for(int i=0;i<1000;i++){ lx[i]=0; } 
}

void loop_Light() {
  // Read the value from photocell and store the data to the lx arrary
  photocellVal = analogRead(photocellPin);
  lx[li++] = photocellVal;
  if(li>999){ li=0; }
  if(ln<1000){ ln++; }  
  
  // Turn on UV light when the light intensity is low
  if (photocellVal > minLight && ledState == 0) {
    digitalWrite(ledPin, HIGH); // turn on LED
    ledState = 1;
  }
  
  // Turn off UV light when the light intensity is sufficient
  if (photocellVal < minLight && ledState == 1) {
    digitalWrite(ledPin, LOW); // turn off LED
    ledState = 0;
  }       
}
  // Formating the data
String get_Light(void){
  String ss="";
  int i, n;
  if(ln!=1000){ n=0; }else{ n = li; }
  for(i=0;i<(ln-1);i++){
    ss += String(lx[n++])+',';
    if(n>999){ n=0; }
  }
  ss += String(lx[n++]);
  return ss;
}
