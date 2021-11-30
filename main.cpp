#include <Encoder.h>
#include <HttpClient.h>
#include <RTC.h>
#include "setup.h"

GET /observations/paris,fr HTTP/1.1
X-Rapidapi-Host: aerisweather1.p.rapidapi.com
X-Rapidapi-Key: 0f5f2241d8msh3dc553f7c2e026ap1011a6jsn5509553ca852
Host: aerisweather1.p.rapidapi.com



//Logic criteria for the system
//Should be able to keep track of how much the shutters are opened and flipped via motor encoders
//Will probably need a logic system to calibrate the motors
//Should be able to update bidirectionally in the case of manual operation

//Sensors/weather api?
//Regulate sunlight so that cloudless days don't burn a hole in your room and cloudy days don't leave the room in darkness (try to maximize light)
//Weather api (if we do get around to a window opening mechanism), here we would need a way to specify our location
//Toggle to have this on (if we do implement an app)
//Doesn't open window when it's pouring outside
//Overrides reaching quota limits
//Possibly implement a "quota" based system to make sure that the room is getting enough fresh air.
//Could take into account the size of the room (app)
//Open the window less but longer for colder days (so that cold air doesn't rush in too quickly)
//Still not sure what kind of format this data is given in from an api (shouldn't be too bad though), would also require wifi connectivity on the board, which would be clunky (although it might be possible to communicate to it through bluetooth? Or a usb connection, since a desktop/laptop space would likely be accessible in the room?)
//Blinds - close when it's dark (light sensor), open at a set time (to help the person wake up)
//Window - how much it opens is decided by temperature/ weather app
//OR for how long it opens varies
//Night - based on user preference - ?

void setup() {
  // Calibration
  ends("chain", "back");
  backChainEncoder = chainEncoder.read();

  }

  // Pull the chain/rod in one direction until the motor cannot pull it anymore
  testChainRod = true;
  while(testChainRod) {
    analogWrite(pwmChain, 40);
    digitalWrite(chainIn1, HIGH);
    digitalWrite(stringIn1, LOW);

    oldEnc = chainEncoder.read();
    wait(50);
    currentEnc = chainEncoder.read();

    if(oldEnc - currentEnc <= 5) {
      testChainRod = false;
      closedChainRodEncoder = chainEncoder.read();
    }
  }
        
}

void loop() {
  // put your main code here, to run repeatedly:
  
  



}
