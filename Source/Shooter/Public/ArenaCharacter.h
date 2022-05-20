#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ArenaCharacter.generated.h"

class UArenaCharacterStats;
class UArenaCharacterInventory;

UCLASS()
class SHOOTER_API AArenaCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AArenaCharacter();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

protected:

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "false"))
	UArenaCharacterStats* StatsComponent;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "false"))
	UArenaCharacterInventory* InventoryComponent;
};
