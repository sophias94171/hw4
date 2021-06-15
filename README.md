# hw4

## Setup and run the Program 


###   #1 XBee Controlled BB Car
  
  1. `$ sudo python3 car_control.py /dev/ttyACM0`
  2. Enter whether west or east (0 represet west ; 1 represent east)
  3. Enter the value of d1(cm)
  4. Enter the value of d2(cm)
  5. Press F2 to let the bb car do reverse parking
  

###   #2 Line Following BB Car
  1. (RPC command to Line Following mode)
  2.  OpenMV would detected the first line that y2 is 0 as the picture below.
  ![]()
  3.  If the diiference between x1 and x2 is < 2 the bb car will go straight.
  4.  If x1 > x2 the car will turn left. If x1 < x2 the car will turn  right.
  5.  The bb car will stop when it had went for a fixed steps.

###   #3 BBCar Position Calibration

## Execution Results

###   #1 XBee Controlled BB Car
1. enter 0(east), the value of d1 d2 as picture below and press F2 to start
    ![]()
  
    demo video:
    https://drive.google.com/file/d/1_hgHBdXZDotuFUCkD5_Mi8R7mMB9JTYX/view?usp=sharing
  
2. enter 0(east) the value of d1 d2 as picture below and press F2 to start
    ![]()
  
    demo video: 
    https://drive.google.com/file/d/1fsoX5sy69TRHaDvnOt_eF2p4Fkr_gPa0/view?usp=sharing


###   #2 Line Following BB Car
1. (RPC command to Line Following mode)
  
  demo video:
  https://drive.google.com/file/d/1xM13LB_xwKywBdLqyiOhrAfjdqj0qEyG/view?usp=sharing


###   #3 BBCar Position Calibration

1. (RPC command to Position Calibration mode)
2. The apriltag used in this homework
![](tag_36h11.png)

2. 


