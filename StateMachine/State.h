#ifndef __CLC_STATE_H__
#define __CLC_STATE_H__

#include "../Common.h"

BEGIN_NAMESPACE

class State
{
public:
	State(const CL_String &name, CL_Callback_0<void> startCallback,
								 CL_Callback_1<void, float> updateCallback,
								 CL_Callback_0<void> stopCallback);
    ~State();
    
    CL_String getName();
    
    void start();
    void update(float delta);
    void stop();
    
private:
    CL_String _name;

	CL_Callback_0<void> _startCallback;
	CL_Callback_1<void, float> _updateCallback;
	CL_Callback_0<void> _stopCallback;
};

END_NAMESPACE

#endif

