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
  obj->addForce(0,0,100);          //apply the force 100[N] in Z direction  
  return 0.00001;    
      
}  
  
void MyController::onRecvMsg(RecvMsgEvent &evt) {  
}  

void MyController::onCollision(CollisionEvent &evt) { 
}
  
extern "C" Controller * createController() {  
  return new MyController;  
}  
