#include "ControllerEvent.h"  
#include "Controller.h"  
#include "Logger.h"  
  
class MyController : public Controller {  
public:  
  void onInit(InitEvent &evt);  
  double onAction(ActionEvent&);  
  void onRecvMsg(RecvMsgEvent &evt); 
  void onCollision(CollisionEvent &evt); 
};  
  
void MyController::onInit(InitEvent &evt) {  
}  
  
double MyController::onAction(ActionEvent &evt) {  

  SimObj *obj = getObj(myname());  //obtaining handle to the agent  
  obj->setAngularVelocity(0,1000,0); //apply the velocity 1000[rad/s] about Y axis  
  return 0.00001;    
      
}  
  
void MyController::onRecvMsg(RecvMsgEvent &evt) {  
}  

void MyController::onCollision(CollisionEvent &evt) { 
}
  
extern "C" Controller * createController() {  
  return new MyController;  
}  
