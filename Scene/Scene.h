#ifndef __CLC_SCENE_H__
#define __CLC_SCENE_H__

#include "../Common.h"

BEGIN_NAMESPACE

class Scene
{
public:
    Scene(const CL_String &name);
    ~Scene();

    CL_String getName() const;

    virtual void update(float delta) = 0;
    virtual void draw() = 0;

private:
    CL_String _name;

};

END_NAMESPACE

#endif
