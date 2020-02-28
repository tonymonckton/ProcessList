//
//  main.cpp
//  ProcessList
//
//  Created by Tony Monckton on 27/02/2020.
//  Copyright © 2020 Tony Monckton. All rights reserved.
//

#include <iostream>
#include "ProcessList.hpp"
#include "ProcessCustomClass.hpp"


int main(int argc, const char * argv[]) {
    // example Usage of Process.
    ProcessList processList = ProcessList("Main Process");
    
    processList += (Process*) new ProcessCustomClass("processClass1");    // custom process
    processList += new Process("process2");
    processList += new Process("process3");
    
    while (processList.execute(0.1f)) {}

    return 0;
}



