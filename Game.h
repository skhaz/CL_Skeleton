#ifndef __CLC_GAME_H__
#define __CLC_GAME_H__

#include <vector>

#include "Common.h"
#include "Kernel.h"

#define FRAMES_PER_SECOND 60

BEGIN_NAMESPACE

class Game
{
public:
	Game(const std::vector<CL_String> &args);
	~Game();

	int run();

	void close();

private:
	Kernel *_kernel;



	void update(float delta);
    void draw();
};

END_NAMESPACE

#endif


