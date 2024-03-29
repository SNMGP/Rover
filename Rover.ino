/*To control the rover, Copy and paste the code below into the Arduino software*/
int E1 = 6; //M1 Speed Control
int E2 = 5; //M2 Speed Control
int M1 = 8; //M1 Direction Control
int M2 = 7; //M2 Direction Control
int leftspeed = 100; //255 is maximum speed
int rightspeed = 100;


void setup(void)
{
int i;
for(i=5;i<=8;i++)
pinMode(i, OUTPUT);
Serial.begin(9600);
}
void loop(void)
{
while (Serial.available() < 1) {} // Wait until a character is received
char val = Serial.read();
Serial.println(val);
switch(val) // Perform an action depending on the command
{
case 'f'://Move Forward
forward (leftspeed,rightspeed);
break;

case 'b'://Move Backwards
reverse (leftspeed,rightspeed);
break;

case 'l'://Turn Left
left (leftspeed,rightspeed);
break;

case 'r'://Turn Right
right (leftspeed,rightspeed);
break;

default:
stop();
break;
}
}
void stop(void) //Stop
{
digitalWrite(E1,LOW);
digitalWrite(E2,LOW);
}
void forward(char a,char b)
{
analogWrite (E1,a);
digitalWrite(M1,LOW);
analogWrite (E2,b);
digitalWrite(M2,LOW);
}
void reverse (char a,char b)
{
analogWrite (E1,a);
digitalWrite(M1,HIGH);
analogWrite (E2,b);
digitalWrite(M2,HIGH);
}
void left (char a,char b)
{
analogWrite (E1,a);
digitalWrite(M1,HIGH);
analogWrite (E2,b);
digitalWrite(M2,LOW);
}
void right (char a,char b)
{
analogWrite (E1,a);
digitalWrite(M1,LOW);
analogWrite (E2,b);
digitalWrite(M2,HIGH);
}
