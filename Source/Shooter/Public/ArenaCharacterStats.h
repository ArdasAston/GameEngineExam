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
	void AddStat(const FName StatFName, float addValue);

	UFUNCTION(BlueprintCallable)
	void DecrementStat(const FName StatFName, float decrementValue);

protected:
	
	UPROPERTY(EditAnywhere, Category = "Stats", meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	float HP = 100.0f;
	UPROPERTY(EditAnywhere, Category = "Stats", meta = (ClampMin = "1.0", ClampMax = "2.0", UIMin = "0.0", UIMax = "2.0"))
	float Speed = 1.0f;
};
