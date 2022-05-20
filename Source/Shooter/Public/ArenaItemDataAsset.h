#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ArenaItemDataAsset.generated.h"

class UDataTable;

UCLASS()
class SHOOTER_API UArenaItemDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, Category = "Item Data")
	FName ItemName;
	UPROPERTY(EditAnywhere, Category = "Item Data")
	UDataTable* StatModifiers = nullptr;
};