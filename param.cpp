
#include "param.h"


Param::Param(){
    
}
Param::Param(String _paramName, String _abbr, float _value){
    name=  _paramName;
    abbr= _abbr;
    value= _value;
    
}

String Param::toString(){
    return (String)name+","+abbr+","+value;
}

void Param::updateValue(float _newValue){
    value = _newValue;
}  

    
