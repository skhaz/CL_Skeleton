 #ifndef __INC_ENTITY_H__
#define __INC_ENTITY_H__

#include "../Kernel.h"

BEGIN_NAMESPACE

class Entity
{
public:
	Entity(CL_Point pos, const CL_String name);
	~Entity();

	int getWidth();
	int getHeight();

	CL_Point getPosition();
	void setPosition(CL_Point point);

	void setAngle(float angle);
	float getAngle();
	void rotate(float angle);

	virtual void update(float delta) = 0;
	virtual void draw() = 0;

protected:
	CL_Point _position;
	int _height;
	int _width;

	Kernel *_kernel;

	CL_Sprite _sprite;

	void drawRectangle(const CL_Colorf &color);
};

END_NAMESPACE

#endif


