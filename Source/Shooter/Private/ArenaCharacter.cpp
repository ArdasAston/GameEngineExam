#include "ArenaCharacter.h"

#include "ArenaCharacterStats.h"
#include "ArenaCharacterInventory.h"
#include "ArenaItem.h"

AArenaCharacter::AArenaCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	StatsComponent = CreateDefaultSubobject<UArenaCharacterStats>(TEXT("Stats"));
	InventoryComponent = CreateDefaultSubobject<UArenaCharacterInventory>(TEXT("Inventory"));
}

void AArenaCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if(OtherActor == nullptr)
	{
		return;	
	}

	bool bIsAnItem = OtherActor->IsA<AArenaItem>();

	if (bIsAnItem && !this->ActorHasTag("Enemy"))
	{
		AArenaItem* Item = Cast<AArenaItem>(OtherActor);
		InventoryComponent->AddItem(Item);

		Item->Destroy();
	}
}