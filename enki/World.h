/*
    Enki - a fast 2D robot simulator
    Copyright (C) 1999-2016 Stephane Magnenat <stephane at magnenat dot net>
    Copyright (C) 2004-2005 Markus Waibel <markus dot waibel at epfl dot ch>
    Copyright (c) 2004-2005 Antoine Beyeler <abeyeler at ab-ware dot com>
    Copyright (C) 2005-2006 Laboratory of Intelligent Systems, EPFL, Lausanne
    Copyright (C) 2006-2008 Laboratory of Robotics Systems, EPFL, Lausanne
    See AUTHORS for details

    This program is free software; the authors of any publication
    arising from research using this software are asked to add the
    following reference:
    Enki - a fast 2D robot simulator
    http://home.gna.org/enki
    Stephane Magnenat <stephane at magnenat dot net>,
    Markus Waibel <markus dot waibel at epfl dot ch>
    Laboratory of Intelligent Systems, EPFL, Lausanne.

    You can redistribute this program and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __ENKI_WORLD_H
#define __ENKI_WORLD_H

#include <set>
#include <map>
#include <vector>
#include "Entity.h"
#include "Component.h"

namespace Enki
{
	class System;
	class RigidBodyPhysics;

	class World
	{
		std::set<Entity> entities;

		std::unique_ptr<RigidBodyPhysics> rigidBodyPhysics;
		std::vector<std::unique_ptr<System>> systems;

		std::map<std::string, std::set<Component*>> componentsByType;

	public:
		template<typename ComponentType>
		ComponentSetRef<ComponentType> getComponentsByType()
		{
			return ComponentSetRef<ComponentType>{ componentsByType[std::string(typeid(ComponentType).name())] };
		}

		virtual void step(double dt);
	};
}

#endif // __ENKI_WORLD_H
