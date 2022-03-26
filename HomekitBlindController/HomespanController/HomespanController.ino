#include "HomeSpan.h"
#include "DEV_Identify.h"      
#include "DEV_RollerBlind.h"

void setup()
{
  Serial.begin(115200);
  
  homeSpan.setStatusPin(2);
  homeSpan.begin(Category::WindowCoverings,"HomeSpan RollerBlind");

  new SpanAccessory();
  new DEV_Identify("Roller Blind","HomeSpan","JerryLin0321","Normal Roller Blind","2.0");
  new Service::HAPProtocolInformation();
    new Characteristic::Version("1.1.0"); 
    
  new DEV_RollerBlind(); 
}

void loop()
{
  homeSpan.poll();
}
