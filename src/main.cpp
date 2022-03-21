#include <Arduino.h>

//#include "WIFIConnector_MKR1000.h"
//#include "MQTTConnector.h"

//Libraries
#include <Keypad.h>//https://github.com/Chris--A/Keypad
//Constants
#define ROWS 4
#define COLS 4
const int DIG_A =   2;            //Broche relier au boutton A
const int DIG_B =   3;            //Broche relier au boutton B
const int DIG_C =   4;            //Broche relier au boutton C
const int DIG_D =   5;            //Broche relier au boutton D


//Parameters

//Creation d'un objet de 4 lignes et 4 colonnes = 16 touches
const char kp4x4Keys[ROWS][COLS]  = {{'1', '2', '3', 'A'}, {'4', '5', '6', 'B'}, {'7', '8', '9', 'C'}, {'*', '0', '#', 'D'}};

byte rowKp4x4Pin [4] = {6, 7, 8, 9};       // Broches representants les 4 lignes de la matrices
byte colKp4x4Pin [4] = {10, 11, 12, 13};       // Broches representants les 4 colonnes de la matrices

//Variables
char ValeurChoisie = 'I';
int Intensite = 3;
int Broche = 0;                   //Pour contenir une broche temporairement
bool ConfirmationBroche    =  false;
bool ConfirmationIntensite = false;

//Initialisation d'une classe au format matrice 4x4
Keypad kp4x4  = Keypad(makeKeymap(kp4x4Keys), rowKp4x4Pin, colKp4x4Pin, ROWS, COLS);
                        

void setup() {

 //Init Serial USB
 Serial.begin(9600);
 //wifiConnect();                  //Branchement au réseau WIFI
 // MQTTConnect();                  //Branchement au broker MQTT
 pinMode(DIG_A, OUTPUT);
 pinMode(DIG_B, OUTPUT);
 pinMode(DIG_C, OUTPUT);
 pinMode(DIG_D, OUTPUT);
}


void loop() 
{
     // digitalWrite(DIG_A,LOW);
      char customKey = kp4x4.getKey();
    switch (customKey)
  {
  case 'A':
         Broche = DIG_A;
         analogWrite(DIG_A,Intensite );
         //delay(3000);
         analogWrite(DIG_B, 0);
         analogWrite(DIG_C, 0);
         analogWrite(DIG_D, 0);
         //delay(8000);
         Intensite = 0;


    break;
  case 'B':
         Broche = DIG_B;
         analogWrite(DIG_A, 0);
         analogWrite(DIG_B, Intensite);
         analogWrite(DIG_C, 0);
         analogWrite(DIG_D, 0);
         //delay(3000);
         Intensite = 0;
    break;
  case 'C':
         Broche = DIG_C;
         analogWrite(DIG_A, 0);
         analogWrite(DIG_B, 0);
         analogWrite(DIG_C, Intensite);
         analogWrite(DIG_D, 0);
    break;
  case 'D':
        Broche = DIG_D;
         analogWrite(DIG_A, 0);
         analogWrite(DIG_B, 0);
         analogWrite(DIG_C, 0);
         analogWrite(DIG_D, Intensite);
    break;
  default:
       Serial.println("Broche");
       //delay(500);
    break;
  }
  

  if (customKey == '*')
  {

     ConfirmationBroche = true;
       Serial.println("ConfirBroche");
  }

  switch (customKey)
 {
    case '1':
        Intensite = int(customKey) - '0';
       Serial.println(Intensite);

      break;
    case '2':
        Intensite = int(customKey) - '0';
      break;
    case '3':
        Intensite = int(customKey) - '0';
      break;
    case '4':
        Intensite = int(customKey) - '0';
      break;
    case '5':
        Intensite = int(customKey) - '0';
      break;
    case '6':
        Intensite = int(customKey) - '0';
      break;
    case '7':
        Intensite = int(customKey) - '0';
      break;
    case '8':
        Intensite = int(customKey) - '0';
      break;
    case '9':
        Intensite = int(customKey) - '0';
      break;
    default:
        Serial.println("Intensite");
      break;
 }

 
  if (customKey == '#')
  {
     ConfirmationIntensite = true;
  }

 /* if (ConfirmationBroche == true )
  { */
    
     Intensite = map(Intensite,0,9,0,255);
    analogWrite(Broche, Intensite);
    /*
       // Serial.println("Correct");
     appendPayload("Broche", Val);  //Ajout de la valeur de la broche A1 au message MQTT
  appendPayload("Intensite", Intensite);  //Ajout de la valeur de la broche A3 au message MQTT
  sendPayload();
     //delay(3000);  */
 //}
  

}

