
#include <controller_rtt/controller_rtt.hpp>

#include <rtt/Component.hpp>         // use for ORO_CREATE_COMPONENT

controller_rtt::controller_rtt( const std::string& name ):
  RTT::TaskContext( name )
{
  std::cout << "constructor" << std::endl;
  addPort( "OutCmd",    port_out_cmd );
}


bool controller_rtt::configureHook(){

  std::cout << "configured" << std::endl;

  return true;

}

bool controller_rtt::startHook() {
          return true;
       }

void controller_rtt::cleanupHook(){
 
    std::cout << "cleaned" << std::endl;
}

controller_rtt::~controller_rtt()
{}

void controller_rtt::updateHook(){

   double time_now = ros::Time::now().toSec();

   cmd.linear.x = breathing_magnitude * cos(time_now/breathing_period);

   port_out_cmd.write(cmd);
   std::cout << "running the loop" << std::endl;


}


void controller_rtt::stopHook() {
          // Your stop code after last updateHook()
       }

ORO_CREATE_COMPONENT( controller_rtt )

