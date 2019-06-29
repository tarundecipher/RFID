/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include <SPI.h>
#include <MFRC522.h>
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio
#include"USART.h"

#include <util/delay.h>

void Send_String(char ar[]){
	int i;
	i=0;
	while(ar[i]!='\0'){
		USART_Transmit(ar[i]);
		i++;
	}
}

 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
void setup() 
{	DDRG |= (1<<5)|(1<<1);
	PORTG &= ~((1<<5)|(1<<1));
	
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "37 B7 E8 A9"||content.substring(1)=="B5 59 3E A1"||content.substring(1)=="3B 52 D9 73") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    if(content.substring(1)=="37 B7 E8 A9"){
    Serial.println("hello_Tarun");
	USART_Init();
	PORTG |=(1<<1);
	
	//Send_String("ATE0\r\n");//echo is turned off
	_delay_ms(1000);
	Send_String("AT+CMGF=1\r\n");//configuring modem in text mode
	
	_delay_ms(2000);
	Send_String("AT+CMGS=\"+919552478089\"\r\n");

	_delay_ms(2000);
	Send_String("TARUN,RFID-37 B7 E8 A9\r\n");
	
	_delay_ms(2000);
	USART_Transmit(26);
	
	_delay_ms(2000);
	//Send_String("AT+CMSS=1\r\n");

	_delay_ms(2000);
	PORTG &=~(1<<1);
	}
    else if(content.substring(1)=="B5 59 3E A1")
    {Serial.println("hello_Pranav");
		USART_Init();
		PORTG |=(1<<1);
		//Send_String("ATE0\r\n");//echo is turned off
		_delay_ms(1000);
		Send_String("AT+CMGF=1\r\n");//configuring modem in text mode
		
		_delay_ms(2000);
		Send_String("AT+CMGS=\"+919552478089\"\r\n");

		_delay_ms(2000);
		Send_String("PRANAV,RFID-B5 59 3E A1\r\n");
		
		_delay_ms(2000);
		USART_Transmit(26);
		
		_delay_ms(2000);
		//Send_String("AT+CMSS=1\r\n");

		_delay_ms(2000);
		PORTG &=~(1<<1);
	}
		
    else if(content.substring(1)=="3B 52 D9 73")
    {Serial.println("hello_Vinit");
		USART_Init();
		PORTG |= (1<<1);	
		//Send_String("ATE0\r\n");//echo is turned off
		_delay_ms(1000);
		Send_String("AT+CMGF=1\r\n");//configuring modem in text mode
		
		_delay_ms(2000);
		Send_String("AT+CMGS=\"+919552478089\"\r\n");

		_delay_ms(2000);
		Send_String("VINIT,RFID-3B 52 D9 73\r\n");
		
		_delay_ms(2000);
		USART_Transmit(26);
		
		_delay_ms(2000);
		//Send_String("AT+CMSS=1\r\n");

		_delay_ms(2000);
		PORTG &=~(1<<1);
	}
   
  

  }
 
 else if(content.substring(1)=="D6 76 D8 FB")  {
    Serial.println(" Guest Access");
  //  Serial.println("bhadva_spotted");
   // Serial.println("bhag_bhosdivale");
   // Serial.println("zaat_ke_baal");
	USART_Init();
		
		PORTG |= ((1<<5)|(1<<1));
	//Send_String("ATE0\r\n");//echo is turned off
	_delay_ms(1000);
	Send_String("AT+CMGF=1\r\n");//configuring modem in text mode
	
	_delay_ms(2000);
	Send_String("AT+CMGS=\"+919552478089\"\r\n");

	_delay_ms(2000);
	Send_String("Guest Access!Entry Stored\r\n");
	
	_delay_ms(2000);
	USART_Transmit(26);
	
	_delay_ms(2000);
	//Send_String("AT+CMSS=1\r\n");

	_delay_ms(2000);
	
	]'['
    delay(3000);
	PORTG&=~((1<<5)|(1<<1));
  }
}
