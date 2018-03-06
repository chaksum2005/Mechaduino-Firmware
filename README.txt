Installation:

1. Calibrate the motor
  1.1 Install the ORIGINAL mechadunio program
  1.2 Type 'c' in serial monitor
  1.3 Paste the loop-up table generated into Utils.cpp in this program
  
2. Upload the ardunio program and install the ROS package


Usage:

1. Input parameters at the bottom of Utils
2. Run ROS interface
    rosrun mechaduino_stepper stepper_control
3. Input degree need to be turn
    rosrun mechaduino_stepper stepper_talker <degree>
    
Integration:
1. ROS node "stepper_control" listen to a topic with a single integer message
    the integer is the input parameter <degree>
