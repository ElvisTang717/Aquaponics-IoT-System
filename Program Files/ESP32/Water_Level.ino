#define WlevelPin 5
int level = 0;
int wl;

void setup_Wlevel() {

}

void loop_Wlevel() {
  level = analogRead(WlevelPin);
  level = map(level,0,8192,0,100);
  wl = level;
}

String get_Wlevel(void){
  String ss="";
  ss = String(wl);
  return ss;
}
