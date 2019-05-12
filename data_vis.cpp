#include "data_vis.h"


DataVis::DataVis(){
    inputsAdded=0;
    paramsAdded=0;
    cmd = "";
    //running = false;
}

void DataVis::addParam(String paramName, String abbr, float value){
    if (paramsAdded >= PARAMS){
        return;
    }
    params[paramsAdded] = Param();
    paramsAdded+=1;

}

void DataVis::addInput(String inputName, String unit, String location, bool isActive, float* floatptr){
    inputs[inputsAdded]= Input(inputName,unit, location, isActive, floatptr);
    inputsAdded+=1;
}

void DataVis::addInput(String inputName, String unit, String location, bool isActive, int* intptr){
    inputs[inputsAdded]= Input(inputName,unit, location, isActive, intptr);
    inputsAdded+=1;
}

void DataVis::waitForInitCmd(){
    while (cmd != "A"){
        cmd = waitForCommand();
    }
    printHeader();
}

void DataVis::waitForStartRunCmd(){
    while (cmd != "B"){
        cmd = waitForCommand();
    }
    
}

void DataVis::printHeader(){
    Serial.flush();
    Serial.println("NEW RUN");
    Serial.println("INPUTS");
    for (int i = 0; i< inputsAdded; i++){
        Serial.println(inputs[i].toString());
    }
    Serial.println("PARAMS");
    for (int i = 0; i< paramsAdded; i++){
        Serial.println(params[i].toString());
    }
    Serial.flush();
}
/*
void DataVis::initRun(uint16_t _readingsPerUpdate,uint16_t _updatesPerRun, uint16_t _updateDelay){
    readingsPerUpdate=_readingsPerUpdate;
    updatesPerRun=_updatesPerRun;
    updateDelay=_updateDelay;
    running=true;
}*/

void DataVis::read(){ 
    for (int i = 0; i< inputsAdded; i++){
        inputs[i].addToBuffer();
    }
}

void DataVis::update(){ 
    for (int i = 0; i< inputsAdded; i++){
        Serial.println(inputs[i].getBuffer());
        inputs[i].flushBuffer();
    }
}



String DataVis::waitForCommand(){
    cmd = "";
    while (!Serial.available()) {}
        while (Serial.available()) // this will be skipped if no data present, leading to                         // the code sitting in the delay function below
    {
        delay(30);  //delay to allow buffer to fill 
        if (Serial.available() >0)
        {
        char c = Serial.read();  //gets one byte from serial buffer
        cmd += c; 
        //makes the string readString
        }
    }
    return cmd;
}

//bool DataVis::isRunning(){return running;}


