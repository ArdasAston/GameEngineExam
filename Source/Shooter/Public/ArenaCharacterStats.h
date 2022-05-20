#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ArenaCharacterStats.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTER_API UArenaCharacterStats : public UActorComponent
{
	GENERATED_BODY()

public:	

	UArenaCharacterStats();

	void UpdateStat(const FString& StatName, float StatValue);

	UFUNCTION(BlueprintCallable)
	float GetStat(const FName StatFName) const;

	UFUNCTION(BlueprintCallable)
	void UseStat(const FName StatFName, float useValue);

protected:
	
	UPROPERTY(EditAnywhere, Category = "Stats", meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	float HP = 100.0f;
	UPROPERTY(EditAnywhere, Category = "Stats", meta = (ClampMin = "10.0", ClampMax = "30.0", UIMin = "0.0", UIMax = "30.0"))
	float Damage = 10.0f;
	UPROPERTY(EditAnywhere, Category = "Stats", meta = (ClampMin = "1.0", ClampMax = "3.0", UIMin = "0.0", UIMax = "3.0"))
	float Speed = 1.0f;
};
