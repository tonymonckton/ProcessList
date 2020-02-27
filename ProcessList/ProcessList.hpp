//
//  ProcessList.hpp
//  Processor
//
//  Created by Tony Monckton on 27/02/2020.
//  Copyright © 2020 Tony Monckton. All rights reserved.
//

#ifndef ProcessList_hpp
#define ProcessList_hpp

#include <stdio.h>
#include "Process.hpp"

class ProcessList : Process {    
public:
    ProcessList(string name) : Process(name)    {   setName(name);  };
    virtual ~ProcessList()                      {};
    
    virtual bool execute(float deltaTime)  {
        bool bStatus = false;
        Process *pNext = getNext();

        // print status...
/*
        while (pNext) {
            cout << ">>process: " << pNext->m_Name << " status: " << Process:ProcessStatusStr(pNext->m_eProcessStatus) << endl;
            pNext = pNext->m_pNext;
        };
 */
        // find and execute active process
        pNext = getNext();  //m_pNext;
        if (pNext) {
            while (pNext){
                if (processActive()) {    cout << "executing: " << pNext->getName() << " " << Process::ProcessStatusStr(pNext->getProcessStatus()) << endl;   };
                if ( pNext->execute(deltaTime) == true)  {   // if process active, end.
                    bStatus = true;
                    break;
                } else {        // completed.. got to next
                    cout << "executing: " << pNext->getName() << " " << Process::ProcessStatusStr(pNext->getProcessStatus()) << endl; 
                    pNext = pNext->getNext();
                }
            }
        }
        return bStatus;
    };
    
    virtual void start(float deltaTime = 0.0f)     {};
    virtual bool update(float deltaTime = 0.0f)    {    return false;   };
    virtual void end(float deltaTime = 0.0f)       {};
  
    void operator += (Process *obj) {
        Process *pNext = this;
        while (pNext->getNext() != NULL) {
            pNext = pNext->getNext();
        };
        pNext->setNext(obj);
    };
    
};


#endif /* ProcessList_hpp */
