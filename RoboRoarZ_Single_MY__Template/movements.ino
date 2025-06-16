// function file to control the movement of the robot

// DO NOT DELETE / COMMENT THESE LINES !!!!

void movements() {
  // BELOW IS THE CODE FOR THE BOTTOM LINE FOLLOWING SENSORS ARE TRIGGERED  

  //  "0" MEANS NO LINE IS PRESENT & "1" MEANS LINE IS PRESENT
  
  if(bottom_left_sensor_status==1 && bottom_right_sensor_status==0){
     // INSERT YOUR CODE HERE 
  }
  
  else if(bottom_left_sensor_status==0 && bottom_right_sensor_status==1){
     // INSERT YOUR CODE HERE 
  }
    
  else{
    my_robot.MoveForward(40);
     // INSERT YOUR CODE HERE
  }
}
