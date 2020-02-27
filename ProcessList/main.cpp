//
//  main.cpp
//  ProcessList
//
//  Created by Tony Monckton on 27/02/2020.
//  Copyright © 2020 Tony Monckton. All rights reserved.
//

#include <iostream>
#include "ProcessList.hpp"

//---------------------
// example processClass

class ProcessClass : Process {
public:
    ProcessClass(string name);
    ProcessClass(float duration);
    virtual ~ProcessClass()                 {};
    virtual void start(float deltaTime)     {};                 // put your custom Start code here.
    virtual bool update(float deltaTime)    { return true; };   // put your custom Update code here.
    virtual void end(float deltaTime)       {};                 // put your custom End code here.
};

ProcessClass::ProcessClass(string name) : Process(name) {};
ProcessClass::ProcessClass(float duration) : Process(duration) {};

//---------------------

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

