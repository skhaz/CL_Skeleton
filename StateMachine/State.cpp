#include "State.h"

BEGIN_NAMESPACE

State::State(const CL_String &name, CL_Callback_0<void> startCallback,
								 CL_Callback_1<void, float> updateCallback,
								 CL_Callback_0<void> stopCallback)
{
	_name = name;

	_startCallback = startCallback;
	_updateCallback = updateCallback;
	_stopCallback = stopCallback;
}

State::~State()
{
}

CL_String State::getName()
{
	return _name;
}
    
void State::start()
{
	if (!_startCallback.is_null())
		_startCallback.invoke();
}

void State::update(float delta)
{
	if (!_updateCallback.is_null())
		_updateCallback.invoke(delta);
}

void State::stop()
{
	if (!_stopCallback.is_null())
		_stopCallback.invoke();
}

END_NAMESPACE
