
#ifndef data_vis_H
#define data_vis_H

#include "param.h"
#include "input.h"
#include "Arduino.h"

#define INPUTS  3
#define PARAMS  3

//enum PlotLocation {TopRight, TopLeft, BottomRight, BottomLeft};

class DataVis{
    public:
        DataVis();
        void addParam(String paramName, String abbr, float value),
        addInput(String inputName, String unit, String plotLocation, bool isActive, int* intptr),
        addInput(String inputName, String unit, String plotLocation, bool isActive, float* floatptr),
        waitForInitCmd(),
        waitForStartRunCmd(),
        printHeader(),
        read(),
        update(),
        //startRun(), 
        //initRun(uint16_t _readingsPerUpdate,uint16_t _updatesPerRun, uint16_t _updateDelay),
       // stepParam(),
        changeParam();
       // bool isRunning();

    private:
        String waitForCommand();
        //unsigned long runLength;
       // bool running;
        Input inputs[INPUTS];
        Param params[PARAMS];
        uint8_t inputsAdded;
        uint8_t paramsAdded;
       // uint16_t readingsPerUpdate, updatesPerRun, updateDelay;
        String cmd;
};

#endif