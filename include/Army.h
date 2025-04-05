#ifndef _H_ARMY_H_
#define _H_ARMY_H_

#include "UnitList.h"
using namespace std;

class Army {
protected:
    int _LF;
    int _EXP;
    string _name;
    
    
public:
    UnitList *unitList;
    Army(Unit **unitArray, int size, string name);
    virtual ~Army() = default;
    virtual void fight(Army *enemy, bool defense = false) = 0;
    virtual string str() const = 0;
};

#endif
