#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArenaItem.generated.h"

class UArenaItemDataAsset;

UCLASS()
class SHOOTER_API AArenaItem : public AActor
{
	GENERATED_BODY()
	
public:	

	AArenaItem();

	UPROPERTY(EditAnywhere, Category = "Item Data")
	UArenaItemDataAsset* ItemData = nullptr;
};