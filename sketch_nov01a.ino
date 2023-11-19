// Define the pin numbers for the RGB LED
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
const int redLed = 12;

const int switchAdd = 3;   
const int switchSub = 2;   
 



void setup() {

  Serial.begin(9600);
 
  // Set the RGB LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
   pinMode(redLed, OUTPUT);

   pinMode(switchAdd, INPUT_PULLUP);
  pinMode(switchSub, INPUT_PULLUP);
}

float temp = -15.0;

void loop() {
  
 if (digitalRead(switchAdd) == LOW) {
    temp += 1;
    delay(100); // Zamedzenie rýchlemu opakovaniu zmien
  }

  if (digitalRead(switchSub) == LOW) {
    temp -= 1;
    delay(100); // Zamedzenie rýchlemu opakovaniu zmien
  }
 Serial.println(temp);


 if(temp > 150)
 {
  digitalWrite(redLed, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(redLed, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
  }
   setTempColor(temp);
//
//   temp = temp + 0.5;
//  delay(50);  // Wait for 1 second
//
//  // Set the color to green
// 
  }

void setTempColor(float tp){
  int t = static_cast<int>(tp);
  if(t < 0){
    setColor(0, 0, 255);
  }
  else if(t < 25){
    int value = map(t, 0, 25, 0, 255 );
    setColor(value, value, 255);
  }
  else if(t < 40){
    int value = map(t, 25, 40, 0, 255 );
    setColor(255 - value, 255, 255 - value);
    }
  else if(t < 90){
    setColor(0, 255, 0);
    }
  else if(t < 150){
    int value = map(t, 90, 150, 0, 255 );
    setColor(value, 255 - value, 0);
    }
    else{ setColor(255, 0, 0);}
}

// Function to set the color of the RGB LED
void setColor(int red, int green, int blue) {
  analogWrite(redPin, 255 - min(red,255));
  analogWrite(greenPin, 255 - min(green,255));
  analogWrite(bluePin, 255 - min(blue,255));
}

int map(int x, int inMin, int inMax, int outMin, int outMax) {
  return static_cast<int>((x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin);
}



