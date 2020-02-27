//
//  ProcessAdstractClass.hpp
//  test
//
//  Created by Tony Monckton on 20/02/2020.
//  Copyright © 2020 Tony Monckton. All rights reserved.
//

#ifndef processAdstractClass_hpp
#define processAdstractClass_hpp

#include <stddef.h>

class ProcessAdstractBaseClass {
public:
    ProcessAdstractBaseClass()              {};
    virtual ~ProcessAdstractBaseClass()     {};

    virtual bool execute(float deltaTime)   = 0;    // execute current state, return true if finished.
    
    // state functions...
    virtual void start(float deltaTime)     = 0;
    virtual bool update(float deltaTime)    = 0;
    virtual void end(float deltaTime)       = 0;
};

#endif /* processAdstractClass_hpp */
