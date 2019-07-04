void setup()
{
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}
int income;
void loop()
{
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  if(Serial.available()>0)
  {
    income=Serial.read();
    income=income-'0';
    digitalWrite(4,LOW);
    delay(10);
    digitalWrite(6,(income&0x2)?HIGH:LOW);
    digitalWrite(5,(income&0x4)?HIGH:LOW);
    digitalWrite(8,(income&0x8)?HIGH:LOW);
    digitalWrite(9,(income&0x1)?HIGH:LOW);
    delay(10);
    digitalWrite(4,HIGH);
    delay(1000);  
    
  }
}
