#include "mbed.h"
// #include "cmath.h"
Serial pc(USBTX,USBRX,115200);
//AnalogIn psd0(A0);
PwmOut led(D9);
void turn(PwmOut &rc,float deg);
template <class T>
T map(T x, T in_min, T in_max, T out_min , T out_max);
// main() runs in its own thread in the OS
int main(){
    float ang = 0., inc = 1;
    led.period_ms(20);
    turn(led,0);
    while(1){
        // turn(led,round(ang));
        led.pulsewidth_us(1000);
        wait_ms(1000);
        led.pulsewidth_us(2000);
        wait_ms(1000);
        pc.printf("%f\n",round(ang));
        // ang+=inc;
        // if(ang>180.f||ang<0.f) inc =-inc;

    }
}
void turn(PwmOut &rc,float deg){
    uint16_t pulseW=map<float>(deg,0.,180.,900.,2100.);
    rc.pulsewidth_us(pulseW);

}
template<class T>
T map(T x, T in_min, T in_max, T out_min , T out_max){
return(x-in_min)*(out_max -out_min)/(in_max-in_min)+out_min;

}
