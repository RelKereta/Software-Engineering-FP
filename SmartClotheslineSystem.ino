#include <ESP32Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <math.h>

#define READ_TIME 1000
#define WIND_SENSOR_PIN 14 //wind sensor pin ESP32 GPIO_14
#define WIND_SPEED_18_PULSE_SECOND 2.0 //in m/s this value can be calibrated
#define ONE_ROTATION_SENSOR 18.0 //pulse per rotation

#define RAIN_DIGITAL_PIN 19
#define RAIN_ANALOG_PIN 18
#define WIND_SENSOR_PIN 14

#define SERVO_RAIN_PIN 13
#define SERVO_WIND_PIN 26

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Servos
Servo servoRain;
Servo servoWind;

// Wind interrupt flag
float WindSpeed;
unsigned long lastPulse = 0;
volatile unsigned long Rotations;
unsigned long gulStart_Read_Timer = 0;
float WindTreshold = 2.0;
bool WindDetect = false; 

void setup() {
  Serial.begin(115200);
  Serial.println("--- Weather Station Control System Starting ---");
  Serial.println("Initializing I2C and LCD...");

  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();
  lcd.print("Starting up...");

  // Servo init
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  servoRain.setPeriodHertz(50);
  servoWind.setPeriodHertz(50);

  // Attach servos (min 500us, max 2400us pulse width)
  servoRain.attach(SERVO_RAIN_PIN, 500, 2400);
  servoWind.attach(SERVO_WIND_PIN, 500, 2400);

  pinMode(RAIN_DIGITAL_PIN, INPUT);
  pinMode(WIND_SENSOR_PIN,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(WIND_SENSOR_PIN),isr_rotation, CHANGE); //Set up the interrupt
  Serial.println("Rotations\tm/s\tknot");
  sei(); //Enables interrupts
  gulStart_Read_Timer - millis();
  lcd.clear();
  Serial.println("Setup complete. Entering loop...");
}

void loop() {
  int rainDigital = digitalRead(RAIN_DIGITAL_PIN);
  int rainAnalog  = analogRead(RAIN_ANALOG_PIN);

  bool rainDetected = (rainDigital == LOW);
    // ----------- WIND LOGIC (Servo 2 on pin 26) ------------
  Serial.print(" | Wind Status: ");
  if((millis() - gulStart_Read_Timer) >= READ_TIME)
  {
    cli(); //Disable interrupts
   
    // Konversi rotation ke kecepatan angin m/s
    WindSpeed = WIND_SPEED_18_PULSE_SECOND / ONE_ROTATION_SENSOR * (float)Rotations / 10.0;
    if(WindSpeed > WindTreshold){
      WindDetect = true;
    }
    else{
      WindDetect = false;
    }
    
    Serial.print("Kecepatan Angin (m/s): ");
    Serial.print(WindSpeed);
    sei(); //Enables interrupts

    Rotations = 0; // reset counter
    gulStart_Read_Timer = millis();

    
  }

  if (WindDetect == true || rainDetected == true) {
     servoRain.write(90);
     delay(1000);
     servoWind.write(90);    // Stay deployed
   } else {
     servoWind.write(0);      // Wind has stopped, close
     Serial.println("NO WIND PULSE (Servo 0)");
     delay(1000);
     servoRain.write(180);
     
   }

  lcd.setCursor(0, 1);
  lcd.print("Wind: ");
  lcd.print(round(WindSpeed));
  lcd.setCursor(0, 0);
  lcd.print("Rain: ");
  if(rainDetected == true){
    lcd.print("Yes");
  }
  else{
    lcd.print("No ");
  }
  //Serial.println("---");




  delay(2000);
}


void isr_rotation()
{
    Rotations++;
}