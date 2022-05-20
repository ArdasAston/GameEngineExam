#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ArenaCharacterInventory.generated.h"

class AArenaItem;

class UArenaCharacterStats;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTER_API UArenaCharacterInventory : public UActorComponent
{
	GENERATED_BODY()

public:	

	UArenaCharacterInventory();

	virtual void InitializeComponent() override;
	virtual void UninitializeComponent() override;

	void AddItem(AArenaItem* i_Item);

protected:

	UPROPERTY(Transient)
	UArenaCharacterStats* CharacterStats = nullptr;
};
