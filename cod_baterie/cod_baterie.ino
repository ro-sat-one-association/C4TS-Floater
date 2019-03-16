long s=0;
float aux;
int nr=0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(38400);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A1);
  s+=sensorValue;
  nr++;
  if(nr==10000){
    s/=10000;

    aux=s*3.4/1024;
    Serial.println(aux,"V pin A1");
    s=0;
    nr=0;
  }
  

}
