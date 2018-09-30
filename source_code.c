int ir_pins[8];
int led_pins[4][3]; 
int i=1;
int check = 0;
unsigned long int timer1;
unsigned long int timer2;
unsigned long int timer;
//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

void setup()
{
  pinMode(A2,INPUT);

  //...
  
  //pinMode(redPin, OUTPUT);
  //pinMode(greenPin, OUTPUT);
  //pinMode(bluePin, OUTPUT);  
}

void loop()
{
    int temp=check_ir(i,i+1);
    int j=hash(i);
// setting the other signals as red
    if(j == 1)
      setcolor(0,0,255,4);
    else
      setcolor(0,0,255,j-1);
      
    if(j==4)
      setcolor(0,0,255,1);
    else// red
      setcolor(0,0,255,j+1);
      
    if(j==3)
      setcolor(0,0,255,1)
    else if(j==4)
      setcolor(0,0,255,2)
    else// red
      setcolor(0,0,255,j+2); 
      
// setting current signal to yellow;
    setcolor(255,0,255,j); //yellow
    timer1 = millis(); 
    while(timer1-millis() > 2500) 
        {
            check = rfid();
            if(check)
            {
                change(j);
                break;
            }
        }
        if(check == 1)
          continue;
//setting current signal to green
     setcolor(255,0,0,j); //green
// change all delays to millis
    timer = millis()   
    // If only one sensor is activated
    if(temp==i)
    {  
        while(timer-millis() > 15000) 
        {
            check = rfid();
            if(check)
            {
                change(j);
                break;
            }
        }
        if(check == 1)
          continue;
      }  
    // If both the sensors are activated
    else if(temp == i+1)
    {  
        while(timer-millis() > 30000) 
        {
            check = rfid();
            if(check)
            {
                change(j);
                break;
            }
        }
        if(check == 1)
          continue;
      } 
     // if neither is activated
    else
    {  
        while(timer-millis() > 10000) 
        {
            check = rfid();
            if(check)
            {
                change(j);
                break;
            }
        }
        if(check == 1)
          continue;
      }
   timer2 = millis(); 
   while(timer2-millis() > 2500) 
        {
            check = rfid();
            if(check)
            {
                change(j);
                break;
            }
        }
        if(check == 1)
          continue;  
    if(i==7)
      i=1;
    else i=i+2; 
}

int hash(int key){
    if(key==1) return 1;
    if(key==3) return 2;
    if(key==5) return 3;
    if(key==7) return 4;
}

void setcolor(int red, int green, int blue,int index)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(led_pins[index][0], red);
  analogWrite(led_pins[index][1],green);
  analogWrite(led_pins[index][2], blue);  
}

int check_ir(int i, int j){
  int x;
  int y;
  delay(1000);
  x = analogRead(i);
  y = analogRead(j);
  delay(1000);
  x = analogRead(i);
  y = analogRead(j);

  if(i>500)  return i;
  else return j;
}

int rfid()
{
   if(Serial.available())
   {
      count = 0;
      while(Serial.available() && count < 12)          // Read 12 characters and store them in input array
      {
         input[count] = Serial.read();
         count++;
         delay(5);
      }
      Serial.print(input);                             // Print RFID tag number 
      
      if((input[0] ^ input[2] ^ input[4] ^ input[6] ^ input[8] == input[10]) && 
         (input[1] ^ input[3] ^ input[5] ^ input[7] ^ input[9] == input[11]))
            return 1;
      else
            return 0;     
   }
}

void change(int i){

  while(rfid()){
    if(j == 1)
      setcolor(0,0,255,4);
    else
      setcolor(0,0,255,j-1);
      
    if(j==4)
      setcolor(0,0,255,1);
    else
      setcolor(0,0,255,j+1);
      
    if(j==3)
      setcolor(0,0,255,1)
    else if(j==4)
      setcolor(0,0,255,2)
    else
      setcolor(0,0,255,j+2); 

    setcolor(255,0,0,j);
  }
  delay(5000);
}
