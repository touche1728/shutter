#include "apicall.h"
#include "setup.h"

//Logic criteria for the system
//Should be able to keep track of how much the shutters are opened and flipped via motor encoders
//Will probably need a logic system to calibrate the motors
//Should be able to update bidirectionally in the case of manual operation

//weather api?
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
  centralize("chain"); 
  centralize("string");


  // Wifi and API Setup
  wifiSetup();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  



}
