#ifndef __CLC_PROGRAM_H__
#define __CLC_PROGRAM_H__

#include <vector>

#include "Common.h"
#include "Game.h"

BEGIN_NAMESPACE

class Program
{
public:
	static int Main(const std::vector<CL_String> &args);
};

END_NAMESPACE

#endif

