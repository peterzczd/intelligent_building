
#include "DHT.h"
#include <LiquidCrystal.h>
#include <Keypad.h>
#define brzeczyk 8
#define trigPin 9
#define echoPin 10
#define DHT11_PIN 48
#define LED_R 24
#define LED_ R 25
#define PIR 38;
#define PIR2 39;
#define PIR1 40;
#define DYM 51;
boolean activated = false;
boolean isActivated;
boolean aktywujal = false;
boolean alarmaktywowany = false;
boolean wpisaneHaslo;
boolean passChangeMode = false;
boolean passChanged = false;
DHT dht;
long duration;
int distance, wejscdyst, obecnydyst, i;
int screenOffMsg =0;
String haslo="1111";
String tempHaslo;
const byte ROWS = 4;
const byte COLS = 4;
char keypressed;
char keyMap[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte rowPins[ROWS] = {14, 15, 16, 17};
byte colPins[COLS] = {18, 19, 20, 21};
Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, ROWS,
COLS);
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); void setup() {
lcd.begin(16,2);
Serial.begin(9600);
dht.setup(DHT11_PIN);
pinMode(brzeczyk, OUTPUT); // Set brzeczyk as an output
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}
void loop() {if (digitalRead() == LOW) {
digitalWrite(LED_R, LOW);
digitalWrite(14, LOW); //Stan ALARM - dioda czerwona
digitalWrite(13, LOW); //Stan ALARM - dioda czerwona
digitalWrite(12, LOW); //Stan ALARM - dioda czerwona
digitalWrite(15, LOW); //Stan ALARM - dioda czerwona
digitalWrite(16, LOW); //Stan ALARM - dioda czerwona
digitalWrite(17, LOW); //Stan ALARM - dioda czerwona
digitalWrite(18, LOW); //Stan ALARM - dioda czerwona
} else
{
digitalWrite(LED_R, HIGH); //Stan ALARM - dioda czerwona
digitalWrite(14, HIGH); //Stan ALARM - dioda czerwona
digitalWrite(13, HIGH); //Stan ALARM - dioda czerwona
digitalWrite(12, HIGH); //Stan ALARM - dioda czerwona
digitalWrite(15, HIGH); //Stan ALARM - dioda czerwona
digitalWrite(16, HIGH); //Stan ALARM - dioda czerwona
digitalWrite(17, HIGH); //Stan ALARM - dioda czerwona
digitalWrite(18, HIGH); //Stan ALARM - dioda czerwona
}
If(digitalRead(8)==HIGH){ // 8
pokoju 1 2 diody(70% mocy)
digitalWrite(30,HIGH);
digitalWrite(31,HIGH);
}
If(digitalRead(9)==HIGH){ 9
1 2 diody(70% mocy)
pin “zapalany” na stronie wtedy zapal w
pin “zapalany” na stronie wtedy zapal w pokoju
digitalWrite(30,HIGH);
digitalWrite(31,HIGH);
digitalWrite(32,HIGH);
}
If(digitalRead(10)==HIGH){
pokoju 2 2 diody(70% mocy)
digitalWrite(33,HIGH);
digitalWrite(34,HIGH);
}
// 8
If(digitalRead(11)==HIGH){ 9
pokoju 2 2 diody(70% mocy)
pin “zapalany” na stronie wtedy zapal w
pin “zapalany” na stronie wtedy zapal w
digitalWrite(33,HIGH);
digitalWrite(35,HIGH);
digitalWrite(34,HIGH);
}
If(digitalRead(11)==HIGH){
pokoju 3 2 diody(70% mocy)
digitalWrite(36,HIGH);
digitalWrite(37,HIGH);
}
// 8
pin “zapalany” na stronie wtedy zapal wIf(digitalRead(12)==HIGH){ 9
pokoju 3 2 diody(70% mocy)
pin “zapalany” na stronie wtedy zapal w
digitalWrite(36,HIGH);
digitalWrite(37,HIGH);
digitalWrite(38,HIGH);
}
//Pobranie informacji o wilgotnosci
int wilgotnosc = dht.getHumidity();
Serial.print(wilgotnosc);
Serial.print("%RH | ");
//Pobranie informacji o temperaturze
int temperatura = dht.getTemperature();
Serial.print(temperatura);
Serial.println("*C");
If(digitalRead(DYM) == HIGH {
Serial.print(wykryto dym lub gaz łatwopalny)
}
if (aktywujal) {
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Alarm bedzie");
lcd.setCursor(0,1);
lcd.print("aktywowany za");
int countdown = 5;
while (countdown != 0) {
lcd.setCursor(14,1);
lcd.print(countdown);
countdown--;
tone(brzeczyk, 700, 100);
delay(500);
pinMode(26, OUTPUT);
digitalWrite(26, LOW);
delay(500);
pinMode(26, OUTPUT);
digitalWrite(26, HIGH);
}
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Alarm Uzbrojony!");
pinMode(26, OUTPUT);digitalWrite(26, LOW);
pinMode(24, OUTPUT);
digitalWrite(24, HIGH);
wejscdyst = zmierzdystans();
aktywujal = false;
alarmaktywowany = true;
}
if (alarmaktywowany == false){
pinMode(24, OUTPUT);
digitalWrite(24, LOW);
}
if (alarmaktywowany == true ){
obecnydyst = zmierzdystans() + 10;
if ( obecnydyst < wejscdyst or digitalRead(PIR) == HIGH or
digitalRead(PIR2) == HIGH) or digitalRead(PIR2) == HIGH)))
{
tone(brzeczyk, 1000); // wycie alarmu
lcd.clear();
enterHaslo();
lokalizuj();
Serial.print("Wykryto włamanie!");
}
}else{
Serial.print(“Nie wykryto włamania”);
pinMode(53, OUTPUT);
digitalWrite(53, LOW);
pinMode(51, OUTPUT);
digitalWrite(51, LOW);
pinMode(49, OUTPUT);
digitalWrite(49, LOW);
pinMode(22, OUTPUT);
digitalWrite(22, LOW);
}
if (!alarmaktywowany) {
if (screenOffMsg == 0 ){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("* - Aktywuj");
lcd.setCursor(0,1);
lcd.print("# - Zmien haslo");
screenOffMsg = 1;
pinMode(53, OUTPUT);
digitalWrite(53, LOW);
pinMode(51, OUTPUT);
digitalWrite(51, LOW);
pinMode(49, OUTPUT);
digitalWrite(49, LOW);pinMode(22, OUTPUT);
digitalWrite(22, LOW);
pinMode(24, OUTPUT);
digitalWrite(24, LOW);
}
keypressed = myKeypad.getKey();
if (keypressed =='*'){
tone(brzeczyk, 1000, 200);
aktywujal = true;
}
else if (keypressed =='#') {
lcd.clear();
int i=1;
tone(brzeczyk, 2000, 100);
tempHaslo = "";
lcd.setCursor(0,0);
lcd.print("Obecne haslo");
lcd.setCursor(0,1);
lcd.print(">");
passChangeMode = true;
passChanged = true;
while(passChanged) {
keypressed = myKeypad.getKey();
if (keypressed != NO_KEY
){
if (keypressed == '0' || keypressed == '1' || keypressed == '2' ||
keypressed == '3' ||
keypressed == '4' || keypressed == '5' || keypressed == '6' ||
keypressed == '7' ||
keypressed == '8' || keypressed == '9' ) {
tempHaslo += keypressed;
lcd.setCursor(i,1);
lcd.print("*");
i++;
tone(brzeczyk, 2000, 100);
}
}
if (i > 5 || keypressed == '#') {
tempHaslo = "";
i=1;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Obecne haslo");
lcd.setCursor(0,1);
lcd.print(">");
}
if ( keypressed == '*') {
i=1;
tone(brzeczyk, 2000, 100);
if (haslo == tempHaslo) {
tempHaslo="";
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Ustaw nowe haslo");
lcd.setCursor(0,1);lcd.print(">");
while(passChangeMode) {
keypressed = myKeypad.getKey();
if (keypressed != NO_KEY){
if (keypressed == '0' || keypressed == '1' || keypressed ==
'2' || keypressed == '3' ||
keypressed == '4' || keypressed == '5' || keypressed ==
'6' || keypressed == '7' ||
keypressed == '8' || keypressed == '9' ) {
tempHaslo += keypressed;
lcd.setCursor(i,1);
lcd.print("*");
i++;
tone(brzeczyk, 2000, 100);
}
}
if (i > 5 || keypressed == '#') {
tempHaslo = "";
i=1;
tone(brzeczyk, 2000, 100);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Ustaw nowe haslo");
lcd.setCursor(0,1);
lcd.print(">");
}
if ( keypressed == '*') {
i=1;
tone(brzeczyk, 2000, 100);
haslo = tempHaslo;
passChangeMode = false;
passChanged = false;
screenOffMsg = 0;
}
}
}
}
}
}
}
}
void enterHaslo() {
int k=5;
tempHaslo = "";
activated = true;
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" !!! ALARM !!! ");
lcd.setCursor(0,1);
lcd.print("Haslo>");
while(activated) {
keypressed = myKeypad.getKey();
pinMode(53, OUTPUT);
digitalWrite(53, HIGH);
pinMode(51, OUTPUT);
digitalWrite(51, HIGH);
pinMode(49, OUTPUT);
digitalWrite(49, HIGH);pinMode(22, OUTPUT);
digitalWrite(22, HIGH);
pinMode(24, OUTPUT);
digitalWrite(24, LOW);
if (keypressed != NO_KEY){
if (keypressed == '0' || keypressed == '1' || keypressed == '2' ||
keypressed == '3' ||
keypressed == '4' || keypressed == '5' || keypressed == '6' ||
keypressed == '7' ||
keypressed == '8' || keypressed == '9' ) {
tempHaslo += keypressed;
lcd.setCursor(k,1);
lcd.print("*");
k++;
}
}
if (k > 9 || keypressed == '#') {
tempHaslo = "";
k=5;
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" !!! ALARM !!! ");
lcd.setCursor(0,1);
lcd.print("Haslo>");
}
if ( keypressed == '*') {
if ( tempHaslo == haslo ) {
activated = false;
alarmaktywowany = false;
noTone(brzeczyk);
screenOffMsg = 0;
}
else if (tempHaslo != haslo) {
lcd.setCursor(0,1);
lcd.print("Zle haslo !");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" !!! ALARM !!! ");
lcd.setCursor(0,1);
lcd.print("Haslo>");
}
}
}
}
long zmierzdystans(){
int i=10;
while( i<=10 ) {
Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration*0.034/2;
sumDistance += distance;
}
int averageDistance= sumDistance/10;
return distance;
}
Void lokalizuj(){
if(digitalRead(PIR) == HIGH){
Serial.print(“Włamanie pokój numer 1 – sypialnia”);
}
if(digitalRead(PIR1) == HIGH){
Serial.print(“Włamanie pokój numer 2 – salon”);
}
if(digitalRead(PIR2) == HIGH){
Serial.print(“Włamanie pokój numer 3 – łazienka”);
}
