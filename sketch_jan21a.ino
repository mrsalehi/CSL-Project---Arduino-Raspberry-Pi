int arrx[10];
int arry[10];

int d1 = 200;
int d2 = 40;

bool show = false;
long long t = 0;


void setup() {
  
  Serial.begin(9600);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  
  pinMode(2, OUTPUT);
}

void loop() {
  
  analogWrite(3, 0);
  analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(9, 0);

  if(analogRead(A2) < 50){
    if(millis() - t > 250){
      show = !show;
      t = millis();
    }
  }

  if(show)
    digitalWrite(2, 1);
  else
    digitalWrite(2, 0);

  for(int i = 0; i < 9; i++){
    arrx[i + 1] = arrx[i];
    arry[i + 1] = arry[i];
  }
  

  int x = analogRead(A0) - 512;
  int y = analogRead(A1) - 512;


  arrx[0] = x;
  arry[0] = y;

  int mx = 0;
  int my = 0;

  for(int i = 0; i < 10; i++){
    mx += arrx[i];
  }
  mx /= 10;


  for(int i = 0; i < 10; i++){
    my += arry[i];
  }
  my /= 10;
  
  
  if((x - y <= d1) && (x - y >= -d1)){

    int v = 0;

    if(my > 0){
      v = map(my, 0, 512, 0, 255);
    }
    else{
      v = map(-my, 0, 512, 0, 255);
    }
    
    analogWrite(3, 2 * v);
  }
  

  if((x + y <= d1) && (x + y >= -d1)){

    int v = 0;

    if(my > 0){
      v = map(my, 0, 512, 0, 255);
    }
    else{
      v = map(-my, 0, 512, 0, 255);
    }
      
    analogWrite(5, 2 * v);
  }


  if((x <= d2) && (x >= -d2)){

    int v = 0;

    if(my > 0){
      v = map(my, 0, 512, 0, 255);
    }
    else{
      v = map(-my, 0, 512, 0, 255);
    }
      
    analogWrite(6, 2 * v);
  }
  

  if((y <= d2) && (y >= -d2)){

    int v = 0;

    if(mx > 0){
      v = map(mx, 0, 512, 0, 255);
    }
    else{
      v = map(-mx, 0, 512, 0, 255);
    }
      
    analogWrite(9, 2 * v);
  }


  delay(35);
}
