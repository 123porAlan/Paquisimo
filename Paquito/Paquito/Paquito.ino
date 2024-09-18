#include "RuedaPaquito.hpp"

// Delantera Derecha
#define SPD_DD  9
#define DIR_DD1 27
#define DIR_DD2 26

// Delantera Izquierda
#define SPD_DI 10
#define DIR_DI1 29
#define DIR_DI2 28

// Trasero Derecho
#define SPD_TD  11
#define DIR_TD1 23
#define DIR_TD2 22

// Trasera Izquierda
#define SPD_TI  12
#define DIR_TI1 25
#define DIR_TI2 24

delay(1000);
class Chasis
{
private:
       RuedaPaquito RDD, RDI, RTD, RTI; 
public:
    Chasis() : 
      RDD(SPD_DD,DIR_DD1,DIR_DD2),
      RDI(SPD_DI,DIR_DI1,DIR_DI2),
      RTD(SPD_TD,DIR_TD1,DIR_TD2),
      RTI(SPD_TI,DIR_TI1,DIR_TI2)
      {
      }
    
    void init()
    {
        RDI.init();
        RDD.init();
        RTI.init();
        RTD.init();
    }

    void testRueda(){
        RTI.avanzar(70);
        delay(1000);
        RTI.frenar();
        delay(1000);
    }

    void right_shift(int speed_fl_fwd, int speed_rl_bck, int speed_rr_fwd, int speed_fr_bck) {
        RDI.avanzar(speed_fl_fwd); 
        RTI.retroceder(speed_rl_bck); 
        RDD.retroceder(speed_fr_bck);
        RTD.avanzar(speed_rr_fwd);
    }

    void left_shift(int speed_fl_bck, int speed_rl_fwd, int speed_rr_bck, int speed_fr_fwd) {
        RDI.retroceder(speed_fl_bck);
        RTI.avanzar(speed_rl_fwd);
        RDD.avanzar(speed_fr_fwd);
        RTD.retroceder(speed_rr_bck);
    }

    void go_advance(int speed) {
        RTI.avanzar(speed);
        RTD.avanzar(speed);
        RDD.avanzar(speed);
        RDI.avanzar(speed);
    }

    void go_back(int speed) {
        RTI.retroceder(speed);
        RTD.retroceder(speed);
        RDD.retroceder(speed);
        RDI.retroceder(speed);
    }

    void left_turn(int speed) { 
        RTI.avanzar(0);
        RTD.avanzar(speed);
        RDD.avanzar(speed);
        RDI.avanzar(0);
    }

    void right_turn(int speed) {
        RTI.avanzar(speed);
        RTD.retroceder(0);
        RDD.retroceder(0);
        RDI.avanzar(speed);
    }

    void left_back(int speed) {
        RTI.avanzar(0);
        RTD.retroceder(speed);
        RDD.retroceder(speed);
        RDI.avanzar(0);
    }

    void right_back(int speed) {
        RTI.retroceder(speed);
        RTD.avanzar(0);
        RDD.avanzar(0);
        RDI.retroceder(speed);
    }

    void clockwise(int speed) {
        RTI.avanzar(speed);
        RTD.retroceder(speed);
        RDD.retroceder(speed);
        RDI.avanzar(speed);
    }

    void countclockwise(int speed) {
        RTI.retroceder(speed);
        RTD.avanzar(speed);
        RDD.avanzar(speed);
        RDI.retroceder(speed);
    }

    void frenar() {
        RTI.frenar();
        RTD.frenar();
        RDD.frenar();
        RDI.frenar();
    }
};

Chasis chasis = Chasis();

void setup() {
  // put your setup code here, to run once:
//Serial.begin(9600);
//Serial.println(0);
chasis.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  //chasis.go_advance(70);
  //delay(1000);
  //chasis.frenar();
  //chasis.go_advance(50);
  delay(1000);
  //chasis.frenar();
  delay(1000);
}
