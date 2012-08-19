#include "TestSM.h"

BEGIN_NAMESPACE

void TestSM::startState1()
{
	CL_Console::write_line("Start State 1: %1", _value);
}

void TestSM::updateState1(float delta)
{
	_value = delta;
	CL_Console::write_line("Update State 1: %1", _value);
}

void TestSM::stopState1()
{
	CL_Console::write_line("Stop State 1: %1", _value);
}

void TestSM::startState2()
{
	CL_Console::write_line("Start State 2: %1", _value);
}

void TestSM::updateState2(float delta)
{
	_value = delta;
	CL_Console::write_line("Update State 2: %1", _value);
}

void TestSM::stopState2()
{
	CL_Console::write_line("Stop State 2: %1", _value);
}

TestSM::TestSM()
{
}

TestSM::~TestSM()
{
}

int TestSM::run()
{
	CL_ConsoleWindow console("Console", 80, 160);

	CL_Callback_0<void> startState1Callback;
	startState1Callback.set(this, &TestSM::startState1);

	CL_Callback_1<void, float> updateState1Callback;
	updateState1Callback.set(this, &TestSM::updateState1);

	CL_Callback_0<void> stopState1Callback;
	stopState1Callback.set(this, &TestSM::stopState1);

	CL_Callback_0<void> startState2Callback;
	startState2Callback.set(this, &TestSM::startState2);

	CL_Callback_1<void, float> updateState2Callback;
	updateState2Callback.set(this, &TestSM::updateState2);

	CL_Callback_0<void> stopState2Callback;
	stopState2Callback.set(this, &TestSM::stopState2);

	StateMachine sm;

	_value = 0.0f;

	sm.createState("State1", startState1Callback, updateState1Callback, stopState1Callback);
	sm.createState("State2", startState2Callback, updateState2Callback, stopState2Callback);

	sm.changeState("State1");
	sm.update(1.0f);

	sm.changeState("State2");
	sm.update(2.0f);

	sm.changeState("State1");
	sm.update(3.0f);

	console.display_close_message();

	return 0;
}

END_NAMESPACE
