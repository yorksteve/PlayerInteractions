// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameInstance.h"

void UMainGameInstance::Init()
{
	Super::Init();
	InventoryManager = UInventoryManager::GetInstance();
}

void UMainGameInstance::Shutdown()
{
	Super::Shutdown();
	UInventoryManager::Cleanup();
}
