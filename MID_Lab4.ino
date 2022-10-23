#define switch1 2 //define name of pins used

#define yellow1 3
#define green1 4
#define red1 5

#define green2 6
#define red2 7
#define yellow2 8

//define the delays for each LED
int LED_blink = 200; 
//define variable for switch press
int switch_read; //defining a variable which will read the state of the switch
int LED_sequence=1; //defining which way the LEDs will light up (left to right or right to left)
int delay_timer (int miliseconds)
{
 int count = 0;
 while(1)
 {
 if(TCNT0 >= 16) // Checking if 1 milisecond has passed
 {
 TCNT0=0;
 count++; 
 if (count == miliseconds) //checking if required miliseconds delay has passed
 {
 count=0;
 break; // exits the loop
 }
 }
 }
 return 0;
}
void setup() {
 //define pins connected to LEDs as outputs and the switch as input
  pinMode(yellow1, OUTPUT); 
  pinMode(green1, OUTPUT);
  pinMode(red1, OUTPUT);
   pinMode(green2, OUTPUT);
    pinMode(red2, OUTPUT);
     pinMode(yellow2, OUTPUT);
     pinMode(switch1, INPUT);


TCCR0A = 0b00000000;
 TCCR0B = 0b00000101; //setting prescaler for timer clock
 TCNT0=0;
}
void loop() {
 switch_read=digitalRead(switch1);
 if (switch_read==LOW){
 LED_sequence=!LED_sequence;
 }
 if (LED_sequence==1){
 //to make green1 LED blink
 digitalWrite(yellow1, HIGH); 
 delay_timer(LED_blink);
 digitalWrite(yellow1, LOW);
 
 //to turn red1 LED blink
 digitalWrite(green1, HIGH);
 delay_timer(LED_blink);
 digitalWrite (green1, LOW);
 
 //green2 blink and so on
 digitalWrite(red1, HIGH);
 delay_timer(LED_blink);
 digitalWrite(red1, LOW);
 
 digitalWrite(green2,HIGH);
 delay_timer(LED_blink);
 digitalWrite(green2, LOW);
 
 digitalWrite(red2, HIGH);
 delay_timer(LED_blink);
 digitalWrite(red2, LOW);
 //green2 blink and so on
 digitalWrite (yellow2, HIGH);
 delay_timer(LED_blink);
 digitalWrite(yellow2, LOW);
 delay_timer(LED_blink);
 
 }
 else 
 {
 digitalWrite(yellow2, HIGH);
 delay_timer (LED_blink);
 digitalWrite(yellow2, LOW);
 digitalWrite(red2, HIGH);
 delay_timer(LED_blink);
 digitalWrite(red2, LOW);
 digitalWrite(green2, HIGH);
 delay_timer(LED_blink);
 digitalWrite(green2, LOW);
 digitalWrite(red1, HIGH);
 delay_timer(LED_blink);
 digitalWrite(red1, LOW);
 digitalWrite(green1, HIGH);
 delay_timer(LED_blink);
 digitalWrite(green1, LOW);
 digitalWrite(yellow1, HIGH); 
 delay_timer(LED_blink);
 digitalWrite (yellow1, LOW);
 delay_timer(LED_blink);
 
 }
}
