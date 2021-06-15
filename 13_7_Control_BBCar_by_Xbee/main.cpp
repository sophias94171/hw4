#include "mbed.h"
#include "bbcar.h"
#include "bbcar_rpc.h"


Ticker servo_ticker;

PwmOut pin5(D5), pin6(D6);

BufferedSerial xbee(D1, D0);
BufferedSerial uart(D10, D9); //tx,rx
BBCar car(pin5, pin6, servo_ticker);

void follow(int x1, int x2){
   int diff = x1 - x2 - 25;
   printf("Diff = %d\n", diff);
   if(diff<2 && diff>-2){
      car.goStraight(-180);
   }
   else if(diff>0){
      car.turn(-180, -0.3);

   }
   else{
      car.turn(-180, 0.3);
   }
   ThisThread::sleep_for(150ms);
   car.stop();
   ThisThread::sleep_for(400ms);
}

int x[4];
int main() {
   int end = 20;
   char buf[256], outbuf[256];
   int step =0;
   FILE *devin = fdopen(&xbee, "r");
   FILE *devout = fdopen(&xbee, "w");
   uart.set_baud(9600);
   printf("Board !!!! im here\r\n");
   // car.turn(-160, -0.3);
   // ThisThread::sleep_for(600ms);
   // car.stop();
   // car.goStraight(-160);
   // ThisThread::sleep_for(1500ms);
   // car.stop();
   while (step<end) {
      if(uart.readable()){
         for (int i=0;;i++){
            char recv[1];
            uart.read(recv, sizeof(recv));
            x[i] = recv[0];
            if(recv[0] =='\n'){
               //printf("\r\n");
               break;
            }
            printf("%d, ", recv[0]);
         }
         printf("Current line(x1, x2, y1, y2): %d, %d, %d, %d \r\n", x[0], x[1], x[2], x[3]);
         if(x[2]>0){
            printf("Go run\r\n");
            follow(x[0], x[1]);
            step++;
         }
      }
   }
   printf("End run \r\n");
}

      // printf("Board !!!! im here\r\n");
      // memset(buf, 0, 256);

      // for( int i = 0; ; i++ ) {
      //    char recv = fgetc(devin);
      //    if(recv == '\n') {
      //       printf("\r\n");
      //       break;
      //    }
      //    buf[i] = fputc(recv, devout);
      // }
      // RPC::call(buf, outbuf);