#define on HIGH
#define off LOW
//########################################################################
int SH_CP = 2;                            //Takteingang Shiftregister
int ST_CP = 3;                            //Takteingang Ausgangsregister
int DS = 4;                               //Datensignal
int daten[] = {on,on,on,on,on,on,on,on};  //Datenarray der Ausgangspins
//########################################################################
void setup()
{
  pinMode(SH_CP,OUTPUT);                  //Festlegen als OUTPUT-PIN
  pinMode(ST_CP,OUTPUT);                  //Festlegen als OUTPUT-PIN
  pinMode(DS,OUTPUT);                     //Festlegen als OUTPUT-PIN
 
  //einmaliges Aufrufen der Prozedur
  allLedOn();                             //alle LEDs werden angeschaltet                        
}
 
void loop()
{
  //hier kann ihr Code stehen
}
 
//##########Register_Funktion#############################################
void allLedOn()
{
  for(int i = 0; i<=7;i++)      //0-7, da 8-Bit Schieberegister
  {
    digitalWrite(ST_CP,LOW);    //Startbedingung für positive Flanke
    digitalWrite(SH_CP,LOW);    //Startbedingung für positive Flanke
   
    digitalWrite(DS,daten[i]);  //Pegel aus 'daten' wird an DS gesetzt
    digitalWrite(SH_CP,HIGH);   //Verschieben von Bit in Shiftregister
  }
  digitalWrite(ST_CP,HIGH);     //Kopieren von Shift- in Ausgangsregister
  //--> alle LEDs an
}
//########################################################################
