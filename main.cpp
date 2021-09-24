int buz=7,red_pin=11,green_pin=10, blue_pin=9,yellow_pin=3;

int gas_sensor=13,flame_sensor=12;

 

void gas_detect(int gas_sensor);

void flame_detect(int flame_sensor);

int gas_flame_detect(int gas_sensor, int flame_sensor);

 

void setup() {                

  // initialize the digital pin as an output.

  Serial.begin(9600);

  pinMode(buz, OUTPUT);     

  pinMode(red_pin, OUTPUT);     

  pinMode(green_pin, OUTPUT);     

  pinMode(blue_pin, OUTPUT);     

  pinMode(yellow_pin, OUTPUT);     

  pinMode(gas_sensor,INPUT);

  pinMode(flame_sensor,INPUT);

  

}

 

 

void loop() {

  int jodo= analogRead(A0);

 

  int gas_value=digitalRead(gas_sensor);

  int flame_value=digitalRead(flame_sensor);

 

  if ((int)(jodo)>900){

      int variable= analogRead(A1);

 

      analogWrite(yellow_pin,variable);

  }

  else{

    digitalWrite(yellow_pin,0);

  }

  

  if(gas_flame_detect(gas_value,flame_value)){

    gas_detect(gas_value);

    flame_detect(flame_value);

  }

  delay(1000);

 

}

 

 

void gas_detect(int gas_sensor)

{

  if(gas_sensor)

  {

    digitalWrite(buz,0);

    digitalWrite(green_pin,0);

  }

  else{

    digitalWrite(buz,1);

    digitalWrite(green_pin,1);}

}

 

void flame_detect(int flame_sensor)

{

  if(flame_sensor){

    digitalWrite(buz,0);

    digitalWrite(blue_pin,0);

  }

  else{

    digitalWrite(buz,1);

    digitalWrite(blue_pin,1);

  }

}

 

int gas_flame_detect(int gas_sensor, int flame_sensor)

{

  if(flame_sensor&&gas_sensor){

    digitalWrite(buz,0);

    digitalWrite(blue_pin,0);

    digitalWrite(red_pin,0);

    digitalWrite(green_pin,0);

    return 1;

  }

  else if(!flame_sensor&&!gas_sensor)

  {

    digitalWrite(buz,1);

    delay(1000);

    digitalWrite(red_pin,1);

    return 0;

  }

  else{

    return 1;

  }

}
