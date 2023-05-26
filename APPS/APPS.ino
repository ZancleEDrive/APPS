// Accelerator Pedal Position Sensor
// V1.0.0 - scheda arancino mignon 


int VAL1,VAL2;
int LEDG = 12;
int LEDR = 5;
void setup() {
 pinMode(LEDG,OUTPUT); //Led di debug verde
 pinMode(LEDR,OUTPUT); //Led di debug rosso
 Serial.begin(9600);
}

void loop() {
  //Assegnazione delle variabili
  VAL1=analogRead(A0);
  VAL2=analogRead(A4);
  
  //Fase di stampa 
  SerialUSB.print("VAL1: ");
  SerialUSB.print(VAL1);
  SerialUSB.print("\t\t\t");
  SerialUSB.print("VAL2: ");
  SerialUSB.println(VAL2);
  SerialUSB.println();
  
  //Fase di controllo
  if( abs(VAL2-VAL1) > 102 ){
    digitalWrite(LEDR,HIGH);
    digitalWrite(LEDG,LOW);
    }
  else{
    digitalWrite(LEDR,LOW);
    digitalWrite(LEDG,HIGH);
  }
  delay(500);
}
