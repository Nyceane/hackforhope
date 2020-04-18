/*
  # Description:
  # When you push the digital button, led and vaporizer turns on for 15 minutes to desterlize
*/
int ledPin = 7;                // choose the pin for the LED
int vaporizer = 5;                // choose the pin for the LED
int inputPin = 6;               // Connect sensor to input pin 3
bool pressed = false;
int count = 0;

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare pushbutton as input
}

void loop(){

  int val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {   
    pressed = true; // check if the input is HIGH
  }
  
  if(pressed == true){
    digitalWrite(ledPin, HIGH); // turn LED ON
    digitalWrite(vaporizer, HIGH); // turn Vaporizer ON
    count += 1;
  }
  else
  {
      digitalWrite(ledPin, LOW);  // turn LED OFF
      digitalWrite(vaporizer, LOW); // turn Vaporizer ON
  }

  if(count > 900)
  {
    count = 0;
    pressed = false;
  }
  delay(1000);
}
