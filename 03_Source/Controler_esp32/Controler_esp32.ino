// //Include Libraries
// #include <SPI.h>
// #include <nRF24L01.h>
// #include <RF24.h>

// //create an RF24 object
// RF24 radio(8, 10);  // CE, CSN

// //address through which two modules communicate.
// const byte address[6] = "00001";

// byte msg[3];
// int value = 0;

// void setup()
// {
//   Serial.begin(115200);
//   delay(2000);

//   radio.begin();

//   //set the address
//   radio.openWritingPipe(address);

//   //Set module as receiver
//   radio.stopListening();

//   Serial.println("inizio ad ascoltare");
//   Serial.println(radio.isChipConnected());
// }

// void loop()
// {
//   //Read the data if available in buffer
//   Serial.println(radio.isChipConnected()); 
//   delay(100); 

//   value = 255;
//   msg[0] = value / 4;
//   radio.write(&msg, sizeof(msg));
// }


//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 10);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  Serial.begin(9600);
  delay(2000);

  radio.begin();

  //set the address
  radio.openReadingPipe(0, address);

  //Set module as receiver
  radio.startListening();

  Serial.println("inizio ad ascoltare");
  Serial.println(radio.isChipConnected());
}

void loop()
{
  //Read the data if available in buffer
  Serial.println(radio.isChipConnected()); 
  delay(100); 

  if (radio.available())
  {
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}
