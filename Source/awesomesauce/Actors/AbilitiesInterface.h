#include "Actor.h"
#include "ActorComponent.h"

class AbilityInterface : public ActorComponent
{
public:
const static int COMPONENT_ID;
virtual int VGetComponentId(void) const
{
return COMPONENT_ID;
}
// Pickup interface
virtual void UseAbility(Actor* pActor) = 0;
}; 