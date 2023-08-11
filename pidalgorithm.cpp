///////////////
//PID.h
///////////////
#include "mbed.h"

int t = 1; //fake time reading (real time doesn't work on this sim)

long us_ticker_read_test(){
    return t;
}

class PIDClass{
public:
    
    PIDClass(double kP, double ki, double kD);
    double calculate(double error);
    
private:
    
    double kP, kI, kD; //constants 
    long lastTime; //timestamp of the previous time
    double sumError;
    
    double calculateP(double error); 
    double calculateI(double error);
    double calculateD(double error);
};
///////////////
//PID.cpp
///////////////

//include PID.h //not neccessary here as we are using one file for everything.

PIDClass::PIDClass(double kP, double kI, double kD){
    lastTime = 0; //No calculations yet, so lastTime is 0;
    
    //TODO: initialize the rest of the private variables here
}

/*
 * Calculates the P section for our PID algorithm.
 * @param error The current error
 * @return the output from this calculation
 */
double PIDClass::calculateP(double error){
    return /*return P calculation*/;
}

/*
 * Calculates the I section for our PID algorithm.
 * @param error The current error
 * @return the output from this calculation
 */
double PIDClass::calculateI(double error){
    long currentTime = us_ticker_read_test();
    
    sumError = /*update sumError*/;
    return /*return I calculation*/;
}

/*
 * Calculates the D section for our PID algorithm.
 * @param error The current error
 * @return the output from this calculation
 */
double PIDClass::calculateD(double error){
    long currentTime = us_ticker_read_test();
    
    double dE = /*calculate derivative of Error*/;
    return /*return D calculation*/;
}

/*
 * Calculates the output for our PID algorithm.
 * @param error The current error
 * @return the output from this calculation
 */
double PIDClass::calculate(double error){
    double result = calculateP(error) + calculateI(error) + calculateD(error);
    
    lastTime = /*set lastTime*/;

    return result;
}

///////////////
//main.cpp // DO NOT EDIT BELOW
///////////////

//#include "PID.cpp" //not neccessary here again as we are using one file for everything.

int main(){
    PIDClass testP(3.2,0,0);
    PIDClass testI(0,2.1,0);
    PIDClass testD(0,0,4.2);
    
    PIDClass testAll(3.2,2.1,4.2);
    
    double errors[5] = {12.4,10.5,10.2,11.5,19.2};
    
    for(int i = 0; i < 5; i ++){
        printf("Results at time %d: P: %f, I: %f D: %f All: %f\n", t,
            testP.calculate(errors[i]),
            testI.calculate(errors[i]),
            testD.calculate(errors[i]),
            testAll.calculate(errors[i])
            );
        t++;
    }
}