#include "Scene.h"

BEGIN_NAMESPACE

Scene::Scene(const CL_String &name)
    : _name(name)
{
}

Scene::~Scene()
{
}

CL_String Scene::getName() const
{
    return _name;
}

END_NAMESPACE
