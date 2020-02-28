# ProcessList

Class to create a list of process using pure virtual functions.

  - C++, Xcode

# Features!

  - Add custom processClasses
  - DeltaTime passed in for onscreen titles etc.


### usage

customProcess:
```sh
class ProcessCustomClass : Process {
public:
    ProcessCustomClass(string name) : Process(name)         {};
    ProcessCustomClass(float duration) : Process(duration)  {};
    virtual ~ProcessCustomClass()           {};
    virtual void start(float deltaTime)     {};                 // custom Start code here.
    virtual bool update(float deltaTime)    { return true; };   // custom Update code here.
    virtual void end(float deltaTime)       {};                 // custom End code here.
};
```

example for to execute ProcessorList

```sh
    ProcessList processList = ProcessList("Main Process");
    
    processList += (Process*) new ProcessCustomClass("processClass1");    // custom process
    processList += new Process("process2");
    processList += new Process("process3");
    
    while (processList.execute(0.1f)) {}
```

License
----

MIT


**Free Software, Hell Yeah!**
