// file to intialise the sensors according to their position on the robot

// DO NOT DELETE / COMMENT THESE LINES !!!!

void sensor_initialisation() {
    bottom_right_sensor_status = my_robot.module1_sensor_status(4);
    bottom_left_sensor_status = my_robot.module1_sensor_status(0);
    movements();

}
