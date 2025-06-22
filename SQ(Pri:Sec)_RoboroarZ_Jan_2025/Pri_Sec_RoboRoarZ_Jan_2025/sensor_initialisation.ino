// file to intialise the sensors according to the shape of the robot
void sensor_initialisation() {
//    front_sensor_status = my_robot.module1_sensor_status(0);
//    right_sensor_status = my_robot.module1_sensor_status(6);
//    bottom_right_sensor_status = my_robot.module1_sensor_status(4);
////    rear_sensor_status = my_robot.module3_sensor_status(0);
//    left_sensor_status = my_robot.module1_sensor_status(10);
//    bottom_left_sensor_status = my_robot.module1_sensor_status(0);
//    movements();
//  if(my_robot.sm_getShape() == 'l'){
//    front_sensor_status = my_robot.module1_sensor_status(0);
//    right_sensor_status = my_robot.module4_sensor_status(4);
//    rear_sensor_status = my_robot.module3_sensor_status(0);
//    left_sensor_status = my_robot.module1_sensor_status(10);
//    movements();
//    
//  }
  if(my_robot.sm_getShape() == 'i'){
//    right_sensor_status = my_robot.module1_sensor_status(6);
    bottom_right_sensor_status = my_robot.module1_sensor_status(4);
//    left_sensor_status = my_robot.module1_sensor_status(10);
    bottom_left_sensor_status = my_robot.module1_sensor_status(0);
//    front_sensor_status = my_robot.module1_sensor_status(0);
//    right_sensor_status = my_robot.module1_sensor_status(4);
//    rear_sensor_status = my_robot.module3_sensor_status(0);
//    left_sensor_status = my_robot.module1_sensor_status(10);
    movements();
    
  }
  if(my_robot.sm_getShape() == 'o'){
//    front_sensor_status = my_robot.module1_sensor_status(0);
//    right_sensor_status = my_robot.module1_sensor_status(4);
//    rear_sensor_status = my_robot.module3_sensor_status(6);
    bottom_left_sensor_status = my_robot.module1_sensor_status(0);
    bottom_right_sensor_status = my_robot.module1_sensor_status(4);
//    right_sensor_status = my_robot.module1_sensor_status(6);
//    left_sensor_status = my_robot.module4_sensor_status(0);
    movements();
    
  }
  

}
