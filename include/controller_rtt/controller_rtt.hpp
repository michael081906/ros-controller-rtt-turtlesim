#ifndef _CONTROLLER_RTT_H
#define _CONTROLLER_RTT_H


#include <rtt/TaskContext.hpp>
#include <rtt/InputPort.hpp>
#include <rtt/OutputPort.hpp>
#include <rtt/OperationCaller.hpp>
#include <rtt/os/TimeService.hpp>

#include <geometry_msgs/Twist.h>

#include <turtlesim/Pose.h> // rostopic info 

class controller_rtt : public RTT::TaskContext {

public:

  enum Errno { ESUCCESS, EFAILURE };

private:

  RTT::OutputPort< geometry_msgs::Twist > port_out_cmd;
    
public:
  
  //! \brief Constructors
  /** 
   * @param name  task name
   */
  controller_rtt( const std::string& name = "controller" );
  
  //! Destructor
  ~controller_rtt();


  bool configureHook();
  bool startHook();
  void updateHook();
  void stopHook();
  void cleanupHook();
   
};

#endif  //_Controller_RTT_H
