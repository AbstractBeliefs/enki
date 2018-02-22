#include <enki/PhysicalEngine.h>
#include <enki/robots/thymio2/Thymio2.h>
#include <iostream>

int main(int argc, char *argv[])
{
	// Create the world
	Enki::World world(200, 200);
	
	// Create a Khepera and position it
	Enki::Thymio2 *thymio = new Enki::Thymio2;
	thymio->pos = Enki::Point(100, 100);
	thymio->leftSpeed = 30;
	thymio->rightSpeed = 20;
	
	// objects are garbage collected by the world on destruction
	world.addObject(thymio);
	
	Enki::Polygon p;
	const double amount = 9;
	const double radius = 5;
	const double height = 20;
	for (double a = 0; a < 2*M_PI; a += 2*M_PI/amount)
		p.push_back(Enki::Point(radius * cos(a), radius * sin(a)));
	Enki::PhysicalObject* o = new Enki::PhysicalObject;
	Enki::PhysicalObject::Hull hull(Enki::PhysicalObject::Part(p, height));
	o->setCustomHull(hull, 1);
	o->pos = Enki::Point(100, 100);
	o->setColor(Enki::Color(0.4,0.6,0.8));
	world.addObject(o);
	
	// Run for some times
	for (unsigned t=0; t<10; t++)
	{
        world.renderObjects();
		//std::cout << "At time " << t << " thymio pos is (" << thymio->pos.x << "," << thymio->pos.y << ")" << std::endl;
		world.step(0.1, 100);
	}
}

