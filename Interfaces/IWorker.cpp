#include "IWorker.h"
#include <string>

class IIWorker {
public:
    virtual ~IIWorker() = default;

    virtual int worker(std::string name,float koef){}


};







