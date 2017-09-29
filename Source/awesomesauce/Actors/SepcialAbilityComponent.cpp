#include "SpecialAbilityComponent.h"
#include <memory>
#include <iostream>

using namespace std;

void SpecialAbilityComponent::UseAbility(Actor* pActor)
{
 unique_ptr<Actor> pStrongActor (pActor);
 if (pStrongActor != nullptr)
 {
 cout <<"Actor ID used special ability!" << (string)(pStrongActor->GetId());
 }
}