//
//  Process.hpp
//  Processor
//
//  Created by Tony Monckton on 22/02/2020.
//  Copyright © 2020 Tony Monckton. All rights reserved.
//

#ifndef Process_hpp
#define Process_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#include "eProcessStatus.hpp"
#include "ProcessAdstractBaseClass.hpp"

class Process : ProcessAdstractBaseClass {
private:
    string          m_Name              = "";
    eProcessStatus  m_eProcessStatus    = eProcessStart;
    float           m_countdownTime     = 0.0f;
    Process         *m_pNext            = NULL;
    
public:
    Process(string name)        {   m_Name = name; };
    Process(float duration)     {   m_countdownTime = duration; };
    virtual ~Process()          {};
    
    bool    processActive()             {   return (m_eProcessStatus != eProcessComplete); };
    Process *getNext()                  {   return m_pNext; };
    void    setNext(Process *obj)       {   m_pNext = obj;  };
    string  getName()                   {   return m_Name;  };
    void    setName(string name)        {   m_Name = name;  };
    eProcessStatus  getProcessStatus()  {   return m_eProcessStatus;    };
    
    static string ProcessStatusStr( eProcessStatus eStatus) {
        string status = "?";
        switch (eStatus) {
            case    eProcessNone:       status = "None";        break;
            case    eProcessStart:      status = "Start";       break;
            case    eProcessUpdate:     status = "Update";      break;
            case    eProcessEnd:        status = "End";         break;
            case    eProcessComplete:   status = "Complete";    break;
            default:
                break;
        }
        return status;
    };
    
    virtual bool execute(float deltaTime)  {
        bool bStatus = true;
        //cout << "execute: "<< m_Name << ") status " << m_eProcessStatus << endl;
        switch (m_eProcessStatus) {
            case eProcessNone:      { break; }
            case eProcessStart:     {
                start(deltaTime);
                m_eProcessStatus = eProcessUpdate;
                break;
            }
            case eProcessUpdate:    {
                if (update(deltaTime)) {
                    m_eProcessStatus = eProcessEnd;
                }
                break;
            }
            case eProcessEnd:       {
                end(deltaTime);
                m_eProcessStatus = eProcessComplete;
                break;
            }
            case eProcessComplete:  {
                bStatus = false;
                break;
            }
        }
        return bStatus;
    }
    
    virtual void start(float deltaTime = 0.0f)     {};
    virtual bool update(float deltaTime = 0.0f)    {
        bool bStatus = false;
        m_countdownTime -= deltaTime;
        if ( m_countdownTime < 0.00001f) {
            m_eProcessStatus = eProcessEnd;
            bStatus = true;
        }
        return bStatus;
    };
    
    virtual void end(float deltaTime = 0.0f)       {};
};


#endif /* Process_hpp */
