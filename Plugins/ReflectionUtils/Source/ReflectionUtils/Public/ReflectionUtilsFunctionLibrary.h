#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReflectionUtilsFunctionLibrary.generated.h"

UCLASS()
class REFLECTIONUTILS_API UReflectionUtilsFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	static FProperty* RetrieveProperty(UObject* InObject, const FString& InPath, void*& OutTarget);

	static FProperty* RetrieveProperty(const UObject* InObject, const FName InPropertyFName);
};