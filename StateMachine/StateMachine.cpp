#include "StateMachine.h"

BEGIN_NAMESPACE

StateMachine::StateMachine()
	: _currentState("") 
{
}

StateMachine::~StateMachine()
{
	_stateMap.clear();
}

State *StateMachine::createState(const CL_String &name, CL_Callback_0<void> startCallback,
														CL_Callback_1<void, float> updateCallback,
														CL_Callback_0<void> stopCallback)
{
	State *state = new State(name, startCallback, updateCallback, stopCallback);

	_stateMap[name] = state;

	return state;
}

void StateMachine::addState(State *state)
{
	_stateMap[state->getName()] = state;
}

void StateMachine::removeState(const CL_String &name)
{
	_stateMap.erase(name);
}

State *StateMachine::getState(const CL_String &name)
{
	return _stateMap[name];
}
 
bool StateMachine::changeState(const CL_String &name)
{
	if (!_stateMap[name])
		return false;

	if (_currentState != "")
		_stateMap[_currentState]->stop();

	_currentState = name;

	if (_currentState != "")
		_stateMap[_currentState]->start();

	return true;
}

void StateMachine::update(float delta)
{
	if (_currentState != "")
		_stateMap[_currentState]->update(delta);
}

END_NAMESPACE
