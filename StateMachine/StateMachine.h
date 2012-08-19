#ifndef __CLC_STATE_MACHINE_H__
#define __CLC_STATE_MACHINE_H__

#include "State.h"

BEGIN_NAMESPACE

#include <map>

class StateMachine
{
public:
    StateMachine();
    ~StateMachine();
    
    State *createState(const CL_String &name, CL_Callback_0<void> startCallback,
											  CL_Callback_1<void, float> updateCallback,
											  CL_Callback_0<void> stopCallback);
    void addState(State *state);
    void removeState(const CL_String &name);

	State *getState(const CL_String &name);

	bool changeState(const CL_String &name);
    
    void update(float delta);
    
private:
    std::map<std::string, State *> _stateMap;

	CL_String _currentState;
};

END_NAMESPACE

#endif

