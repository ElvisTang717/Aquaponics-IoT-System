int Moistpin = 2;
int value ;
int minMoisture = 10;
int pumpPin = 7;
int pumpState = 0;

short mn=0, mi=0;
int mx[1000];

void setup_Moist()
{
  pinMode(pumpPin, OUTPUT);
  for(int i=0;i<1000;i++){ mx[i]=0; }
}
 
void loop_Moist()
{
  value= analogRead(Moistpin);
  value = map(value,0,8192,100,0);
  mx[mi++] = value;
  if(mi>999){ mi=0; }
  if(mn<1000){ mn++; }
  
  // Turn on the pump when the soil is too dry
  if (value < minMoisture && pumpState == 0) {
    digitalWrite(pumpPin, HIGH); // turn on pump
    pumpState = 1;
  }
  
  // Turn off the pump when the soil is wet
  if (value > minMoisture && pumpState == 1) {
    digitalWrite(pumpPin, LOW); // turn off pump
    pumpState = 0;
  }  
}
  // Formating the data
String get_Moist(void){
  String ss="";
  int i, n;
  if(mn!=1000){ n=0; }else{ n = mi; }
  for(i=0;i<(mn-1);i++){
    ss += String(mx[n++])+',';
    if(n>999){ n=0; }
  }
  ss += String(mx[n++]);
  return ss;
}
