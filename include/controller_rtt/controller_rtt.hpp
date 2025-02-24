#ifndef _CONTROLLER_RTT_H
#define _CONTROLLER_RTT_H


#include <rtt/TaskContext.hpp>
#include <rtt/InputPort.hpp>
#include <rtt/OutputPort.hpp>
#include <rtt/OperationCaller.hpp>
#include <rtt/os/TimeService.hpp>

#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>

#include <turtlesim/Pose.h> // rostopic info 

class controller_rtt : public RTT::TaskContext {

public:

  enum Errno { ESUCCESS, EFAILURE };

private:

  RTT::OutputPort< geometry_msgs::Twist > port_out_cmd;

  geometry_msgs::Twist cmd;
  double  breathing_magnitude     = 0.5;
  double  breathing_period        = 3;
    
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
