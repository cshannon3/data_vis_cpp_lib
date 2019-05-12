
#ifndef param_H
#define param_H

#include "Arduino.h"

class Param{
    public:
    Param();
    Param(String _paramName, String _abbr, float _value);
    String toString(void);
    void updateValue(float _newValue);

    private:
        String name, abbr;
        float value;
        
};

#endif