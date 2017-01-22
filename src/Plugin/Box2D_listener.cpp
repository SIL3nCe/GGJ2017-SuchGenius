#include "Box2D_listener.h"

/**
 * @brief Constructor
 */
Box2DListener::Box2DListener(void)
{
	// ...
}

/**
 * @brief Destructor
 */
Box2DListener::~Box2DListener(void)
{
	// ...
}

void Box2DListener::Initialize(PluginGGJ2017 * pPlugin)
{
	m_pPlugin = pPlugin;
}

/**
* @brief BeginContact
*/
void Box2DListener::BeginContact(b2Contact * contact)
{
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();

	bool sensorA = fixtureA->IsSensor();
	bool sensorB = fixtureB->IsSensor();

	if (sensorA)
	{
		Block * pBlockB = static_cast<Block *>(contact->GetFixtureB()->GetBody()->GetUserData());
		if (Block::PLAYER == pBlockB->GetType())
		{
			m_pPlugin->SetPlayerOnSensorA(true);
		}
	}
	else if (sensorB)
	{
		Block * pBlockA = static_cast<Block *>(contact->GetFixtureA()->GetBody()->GetUserData());
		if (Block::PLAYER == pBlockA->GetType())
		{
			m_pPlugin->SetPlayerOnSensorB(true);
		}
	}
}

/**
* @brief EndContact
*/
void Box2DListener::EndContact(b2Contact * contact)
{
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();

	bool sensorA = fixtureA->IsSensor();
	bool sensorB = fixtureB->IsSensor();

	if (sensorA)
	{
		Block * pBlockB = static_cast<Block *>(contact->GetFixtureB()->GetBody()->GetUserData());
		if (Block::PLAYER == pBlockB->GetType())
		{
			m_pPlugin->SetPlayerOnSensorA(false);
		}
	}
	else if (sensorB)
	{
		Block * pBlockA = static_cast<Block *>(contact->GetFixtureA()->GetBody()->GetUserData());
		if (Block::PLAYER == pBlockA->GetType())
		{
			m_pPlugin->SetPlayerOnSensorB(false);
		}
	}
}

