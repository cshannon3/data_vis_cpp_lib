
#include "input.h"
#include "Arduino.h"

Input::Input(){
    
}
Input::Input(String _name,String _unit, String _plotLocation, bool _isActive,float* _floatInputPtr){
    name = _name;
    unit = _unit;
    floatInputPtr = _floatInputPtr;
    isActive = _isActive;
    plotLocation=_plotLocation;
    inputType = FLOAT;
    
}

Input::Input(String _name, String _unit, String _plotLocation, bool _isActive,int* _intInputPtr){
    name = _name;
    unit = _unit;
    intInputPtr=_intInputPtr;
    isActive = _isActive;
    plotLocation=_plotLocation;
    inputType= INT;
}

void Input::flushBuffer(){
    outputString = name+":";
}


String Input::toString(){
    String o = name +","+unit+","+plotLocation+ ",";
    if (isActive){
        o+="active";
    }
    return o;
}
void Input::addToBuffer(){
    if (inputType == FLOAT){
        outputString += (String)*floatInputPtr + ",";
    }
    else{
        outputString += (String)*intInputPtr + ",";
    }
}  

String Input::getBuffer(){return outputString;}