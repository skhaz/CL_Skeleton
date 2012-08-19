#include "Entity.h"

BEGIN_NAMESPACE

Entity::Entity(CL_Point pos, const CL_String name)
{
	_kernel = Kernel::getInstance();

	_sprite = CL_Sprite(_kernel->getGraphicContext(), name, &_kernel->getResourceManager());

	_width = _sprite.get_width();
	_height = _sprite.get_height();
	_position = pos;
}

Entity::~Entity()
{}

int Entity::getWidth()
{
	return _width;
}

int Entity::getHeight()
{
	return _height;
}

CL_Point Entity::getPosition()
{
	return _position;
}

void Entity::setPosition(CL_Point point)
{
	_position = point;
}

void Entity::setAngle(float angle)
{
	_sprite.set_angle(CL_Angle::from_radians(angle));
}

float Entity::getAngle()
{
	return _sprite.get_angle().to_radians();
}

void Entity::rotate(float angle)
{
	_sprite.rotate(CL_Angle::from_radians(angle));
}

void Entity::drawRectangle(const CL_Colorf &color)
{
	CL_Vec2i positions[] =
	{
		CL_Vec2i(_position.x, _position.y),
		CL_Vec2i(_position.x + _width, _position.y),
		CL_Vec2i(_position.x + _width, _position.y + _height),
		CL_Vec2i(_position.x, _position.y + _height)
	};
	
	CL_PrimitivesArray vertex_data(_kernel->getGraphicContext());
	vertex_data.set_attributes(0, positions);
	vertex_data.set_attribute(1, color);
	_kernel->getGraphicContext().draw_primitives(CL_PrimitivesType::cl_lines, 4, vertex_data);
}

END_NAMESPACE
