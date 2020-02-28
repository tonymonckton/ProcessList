//
//  ProcessCustomClass.hpp
//  ProcessList
//
//  Created by Tony Monckton on 28/02/2020.
//  Copyright © 2020 Tony Monckton. All rights reserved.
//

#ifndef ProcessCustomClass_hpp
#define ProcessCustomClass_hpp

#include <stdio.h>
#include "Process.hpp"


class ProcessCustomClass : Process {
public:
    ProcessCustomClass(string name) : Process(name)         {};
    ProcessCustomClass(float duration) : Process(duration)  {};
    virtual ~ProcessCustomClass()           {};
    virtual void start(float deltaTime)     {};                 // put your custom Start code here.
    virtual bool update(float deltaTime)    { return true; };   // put your custom Update code here.
    virtual void end(float deltaTime)       {};                 // put your custom End code here.
};

#endif /* ProcessCustomClass_hpp */
