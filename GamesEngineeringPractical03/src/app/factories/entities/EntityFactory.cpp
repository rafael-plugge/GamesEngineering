#include "stdafx.h"
#include "EntityFactory.h"

app::fact::EntityFactory::EntityFactory(app::Registry & registry)
	: BaseFactory()
	, m_registry(registry)
{
}
