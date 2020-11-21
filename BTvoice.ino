#include <SoftwareSerial.h>

SoftwareSerial BT(0, 1); //TX, RX respetively
String readvoice;

void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  //pinMode(7, OUTPUT);
  //pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);

}

void loop() {
  while (BT.available()) { //Check if there is an available byte to read
    delay(100); //Delay added to make thing stable
    char c = BT.read(); //Conduct a serial read
    readvoice += c; //build the string- "forward", "reverse", "left" and "right"
  }
  if (readvoice.length() > 0) {
    Serial.println(readvoice);

    if (readvoice == "Forward")
    {
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(6,  HIGH);
      digitalWrite(7,  LOW);
    }
      
      
    else if (readvoice == "Backward")
    {
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(6,  LOW);
      digitalWrite(7,  HIGH);
    }
      
    else if (readvoice == "right")
    {
      digitalWrite (4, HIGH);
      digitalWrite (5, LOW);
      digitalWrite (6, LOW);
      digitalWrite (7, LOW);
      delay (100);

    }

    else if ( readvoice == "left")
    {
      digitalWrite (4, LOW);
      digitalWrite (5, HIGH);
      digitalWrite (6, LOW);
      digitalWrite (7, LOW);
      delay (100);
    }

    else if (readvoice == "stop")
    {
      digitalWrite (4, LOW);
      digitalWrite (5, LOW);
      digitalWrite (6, LOW);
      digitalWrite (7, LOW);
      delay (100);
    }



    readvoice = "";
  }
} //Reset the variable
