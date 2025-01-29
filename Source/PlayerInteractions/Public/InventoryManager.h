// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupItem.h"
#include "UObject/Object.h"
#include "InventoryManager.generated.h"

UCLASS()
class PLAYERINTERACTIONS_API UInventoryManager : public UObject
{
	GENERATED_BODY()

public:
	UInventoryManager();
	~UInventoryManager();

	static UInventoryManager* GetInstance();
	
	void AddItem(APickupItem* Item);

	void RemoveItem(APickupItem* Item);
	
	bool HasItem(const APickupItem* Item) const;
	bool HasItem(const FString& ItemName) const;
	bool ItemHasTag(const FName& TagName) const;

	static void Cleanup();

private:
	static UInventoryManager* Instance;

	TArray<APickupItem*> Items;
};
