// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManager.h"

UInventoryManager* UInventoryManager::Instance = nullptr;

UInventoryManager::UInventoryManager()
{
}

UInventoryManager::~UInventoryManager()
{
	UE_LOG(LogTemp, Warning, TEXT("InventoryManager Destroyed"));
}

UInventoryManager* UInventoryManager::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = NewObject<UInventoryManager>();
	}
	return Instance;
}

void UInventoryManager::AddItem(APickupItem* Item)
{
	if (!Item || HasItem(Item)) return;

	Items.Add(Item);
	UE_LOG(LogTemp, Warning, TEXT("Added Item: %s"), *Item->GetName());
}

void UInventoryManager::RemoveItem(APickupItem* Item)
{
	if (!Item || !HasItem(Item)) return;

	Items.Remove(Item);
	UE_LOG(LogTemp, Warning, TEXT("Removed Item: %s"), *Item->GetName());
}

bool UInventoryManager::HasItem(const APickupItem* Item) const
{
	return Items.Contains(Item);
}

bool UInventoryManager::HasItem(const FString& ItemName) const
{
	for (const APickupItem* Item : Items)
	{
		if (Item && Item->GetName() == ItemName) return true;
	}

	return false;
}

bool UInventoryManager::ItemHasTag(const FName& TagName) const
{
	for (const APickupItem* Item : Items)
	{
		if (Item && Item->ActorHasTag(TagName)) return true;
	}

	return false;
}

void UInventoryManager::Cleanup()
{
	Instance->ConditionalBeginDestroy();
	Instance = nullptr;
}