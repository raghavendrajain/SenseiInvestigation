#include <iostream>
#include <fstream>
#include <iomanip>
#include "ControllerEvent.h"
#include "Controller.h"
#include "Logger.h"

// #include "math.h" 

using namespace std;

ofstream myfile ("example.csv", ios_base::trunc); // empty the already existing content of the file and write it as new!


  
class MyController : public Controller {  
public:  
  void onInit(InitEvent &evt);  
  double onAction(ActionEvent&);  
  void onRecvMsg(RecvMsgEvent &evt); 
  void onCollision(CollisionEvent &evt); 
};  
  
void MyController::onInit(InitEvent &evt) {  

     myfile.flush();
     if (myfile.is_open())
  	 {
	 	myfile << setprecision(2) << std::fixed;
	 	myfile  << "X" << " , " << " Y " << " \n ";  
	 }
	
}  
  
double MyController::onAction(ActionEvent &evt) {  

  SimObj *obj = getObj(myname());  //obtaining handle to the agent  
  // obj->setLinearVelocity(0,0,100); //apply the linear velocity 100[m/s] in Z axis  
  obj->addForce(0,0,10000); //apply the orce of 10000[N] in Z axis  



  Vector3d currentVelocity;
  obj->getLinearVelocity(currentVelocity);
  
  if (myfile.is_open() && (evt.time() < 15) )
  {
  		myfile << currentVelocity.x() << " , "  <<  currentVelocity.z() << "\n" ;
  }
  if(evt.time() > 15)
  {
  	exit(0);
  }

  return 0.00001;    
      
}
  
void MyController::onRecvMsg(RecvMsgEvent &evt) {  
}  

void MyController::onCollision(CollisionEvent &evt) { 
}
  
extern "C" Controller * createController() {  
  return new MyController;  
}  
