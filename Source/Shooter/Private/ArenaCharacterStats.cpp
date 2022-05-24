#include "ArenaCharacterStats.h"

#include "Engine.h"

#include "ReflectionUtilsFunctionLibrary.h"

UArenaCharacterStats::UArenaCharacterStats()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UArenaCharacterStats::UpdateStat(const FString& StatName, float StatValue)
{
	FString Path = "This";
	Path += ".";
	Path += StatName;

	void* OutObject = nullptr;
	FProperty* StatProperty = UReflectionUtilsFunctionLibrary::RetrieveProperty(this, Path, OutObject);

	if (StatProperty != nullptr)
	{
		FFloatProperty* FloatProperty = CastField<FFloatProperty>(StatProperty);
		if (FloatProperty != nullptr)
		{

			FloatProperty->SetPropertyValue_InContainer(OutObject, StatValue);

			if (GEngine != nullptr)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Stats update"));
			}
		}
	}
}

float UArenaCharacterStats::GetStat(const FName StatFName) const
{
	FProperty* StatProperty = UReflectionUtilsFunctionLibrary::RetrieveProperty(this, StatFName);
	if (StatProperty != nullptr)
	{
		FFloatProperty* FloatProperty = CastField<FFloatProperty>(StatProperty);
		if (FloatProperty != nullptr)
		{
			return FloatProperty->GetPropertyValue_InContainer(this);
		}
	}
	return FLT_MIN;
}

void UArenaCharacterStats::AddStat(const FName StatFName, float addValue)
{
	FProperty* StatProperty = UReflectionUtilsFunctionLibrary::RetrieveProperty(this, StatFName);
	if (StatProperty != nullptr)
	{
		FFloatProperty* FloatProperty = CastField<FFloatProperty>(StatProperty);
		if (FloatProperty != nullptr)
		{
			const float currentValue = FloatProperty->GetPropertyValue_InContainer(this);
			const float newValue = addValue > currentValue ? 0 : currentValue + addValue;
			FloatProperty->SetPropertyValue_InContainer(this, newValue);
		}
	}
}

void UArenaCharacterStats::DecrementStat(const FName StatFName, float decrementValue)
{
	FProperty* StatProperty = UReflectionUtilsFunctionLibrary::RetrieveProperty(this, StatFName);
	if (StatProperty != nullptr)
	{
		FFloatProperty* FloatProperty = CastField<FFloatProperty>(StatProperty);
		if (FloatProperty != nullptr)
		{
			const float currentValue = FloatProperty->GetPropertyValue_InContainer(this);
			const float newValue = decrementValue > currentValue ? 0 : currentValue - decrementValue;
			FloatProperty->SetPropertyValue_InContainer(this, newValue);
		}
	}
}
