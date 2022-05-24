#include "ArenaCharacterInventory.h"
#include "ArenaCharacterStats.h"
#include "ArenaLogContent.h"
#include "ArenaItem.h"
#include "ArenaItemDataAsset.h"
#include "ArenaItemStatModifier.h"

#pragma optimize("", off)

UArenaCharacterInventory::UArenaCharacterInventory()
{
	PrimaryComponentTick.bCanEverTick = false;

	bWantsInitializeComponent = true;
}

void UArenaCharacterInventory::InitializeComponent()
{
	Super::InitializeComponent();

	AActor* Owner = GetOwner();
	if (Owner != nullptr)
	{
		CharacterStats = Owner->FindComponentByClass<UArenaCharacterStats>();
	}
}

void UArenaCharacterInventory::UninitializeComponent()
{
	Super::UninitializeComponent();

	CharacterStats = nullptr;
}

void UArenaCharacterInventory::AddItem(AArenaItem* i_Item)
{
	if (CharacterStats == nullptr)
	{
		CharacterStats = GetOwner()->FindComponentByClass<UArenaCharacterStats>();
	}
	
	if (CharacterStats == nullptr)
	{
		UE_LOG(LogArena, Warning, TEXT("Missing Character Stats"));
		return;
	}

	if (i_Item == nullptr)
	{
		UE_LOG(LogArena, Warning, TEXT("Invalid Item"));
		return;
	}

	UArenaItemDataAsset* DataAsset = i_Item->ItemData;

	if (DataAsset == nullptr)
	{
		UE_LOG(LogArena, Warning, TEXT("Invalid Item DataAsset"));
		return;
	}

	UE_LOG(LogArena, Log, TEXT("Added Item %s"), *DataAsset->ItemName.ToString());

	UDataTable* Modifiers = DataAsset->StatModifiers;

	if (Modifiers == nullptr)
	{
		UE_LOG(LogArena, Warning, TEXT("Invalid Item DataTable"));
		return;
	}

	static const FString ContentString(TEXT("UarenaCharacterInventory::AddItem"));

	TArray<FArenaItemStatModifier*> Rows;
	Modifiers->GetAllRows(ContentString, Rows);

	int NumRows = Rows.Num();

	for (size_t RowIndex = 0; RowIndex < NumRows; ++RowIndex)
	{
		if (Rows[RowIndex]->StatName == "HP")
		{
			FArenaItemStatModifier* Row = Rows[RowIndex];
		}
		else
		{
			FArenaItemStatModifier* Row = Rows[RowIndex];
			CharacterStats->UpdateStat(Row->StatName, Row->Value);
		}
	}
}

#pragma optimize("", on)