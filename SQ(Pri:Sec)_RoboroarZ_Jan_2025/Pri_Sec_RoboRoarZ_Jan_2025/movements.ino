// function file to control the movement of the robot
void movements() {
//  Serial.println("Movements");
//  if (left_sensor_status==0 && right_sensor_status==0){
//    Serial.println("1 Move Straight");
//    my_robot.MoveForward(40);
//  }

//  else if(right_sensor_status==0 && left_sensor_status==0){
//    
//    my_robot.sm_reset_M1();
////    my_robot.sm_reset_M2();
////    my_robot.sm_reset_M3();
////    my_robot.sm_reset_M4();
//    my_robot.stopSmorphi_single();
//  }


  

//  else if(front_sensor_status==0 && right_sensor_status==0){
//    my_robot.CenterPivotLeft(80);
//    delay(1000);
//  }
//
//  else if(front_sensor_status==0 && left_sensor_status==0){
//    my_robot.CenterPivotRight(80); 
//    delay(1000);
//  }

//  else if(right_sensor_status==0){
//    my_robot.CenterPivotLeft(270);
//    delay(10);
//  }
//
//  else if(left_sensor_status==0){
//    my_robot.CenterPivotRight(270);
//    delay(10);
//  }

//  else if(front_sensor_status==0){
//
//    my_robot.CenterPivotLeft(80);
//    delay(10);
//    my_robot.CenterPivotRight(80);
//    delay(20);
//  }
  
//  else if(last_action=="pivot_right" || rear_sensor_status==0 && left_sensor_status==0){
//    pivot_right;
//    delay(300);
//    last_action="nill";
//  }
//  else if(right_sensor_status==1 && front_sensor_status==0 && left_sensor_status==0 && rear_sensor_status==1){
//    Serial.println("Free to move right");
//    pivot_right();
////
//  }      
//  else{
//    Serial.println("Move Forward");
//    my_robot.MoveForward(40);
  if(bottom_left_sensor_status==1 && bottom_right_sensor_status==0){
    my_robot.CenterPivotLeft(270);
    delay(15); 
  }

  else if(bottom_left_sensor_status==0 && bottom_right_sensor_status==1){
    my_robot.CenterPivotRight(270);
    delay(15); 
  }
  
  else{
    my_robot.MoveForward(40);
//    delay(500); 
  }
//  }
}
