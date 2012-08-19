#ifndef __CLC_TESTSM_H__
#define __CLC_TESTSM_H__

#include "Common.h"
#include "StateMachine/StateMachine.h"

BEGIN_NAMESPACE

class TestSM
{
public:
	TestSM();
	~TestSM();

	int run();

	void startState1();
	void updateState1(float delta);
	void stopState1();

	void startState2();
	void updateState2(float delta);
	void stopState2();

private:
	float _value;

};

END_NAMESPACE

#endif
