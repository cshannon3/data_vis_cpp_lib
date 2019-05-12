
#ifndef input_H
#define input_H
#include "Arduino.h"
enum InputType{FLOAT, INT };

class Input{
    public:
        Input();
        Input(String _name,   String _unit, String _plotLocation, bool _isActive, float* _floatInputPtr);
        Input(String _name,  String _unit, String _plotLocation,  bool _isActive, int* _intInputPtr);
        String toString(void),
        getBuffer(void);
        void flushBuffer(void),
        addToBuffer(void);
        
    private:
        int* intInputPtr;
        float* floatInputPtr;
        //char input_buffer[300];
        String outputString;
        String name,unit, plotLocation;
        bool isActive;
        InputType inputType;
     
};

#endif

// #ifndef input_H
// #define input_H
// enum InputType{FLOAT, INT };

// class Input{
//     public:

//         Input(String _name, String _abbr,  String _unit, float* _floatInputPtr);
//         Input(String _name, String _abbr,  String _unit, int* _intInputPtr);
//         String toString(void);
//         String flushBuffer(void);
//         void addToBuffer(void);

//     private:
//         int* intInputPtr;
//         float* floatInputPtr;
//         char input_buffer[300];
//         char *name, *abbr, *unit;
//         InputType inputType;
     
// };

// #endif