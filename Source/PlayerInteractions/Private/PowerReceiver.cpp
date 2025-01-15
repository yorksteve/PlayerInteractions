// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerReceiver.h"

#include "PowerCore.h"


// Sets default values
APowerReceiver::APowerReceiver()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TargetPowerLevel = 0.f;
}

// Called when the game starts or when spawned
void APowerReceiver::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerReceiver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APowerReceiver::OnPowerCoreDropped(APowerCore* PowerCore)
{
	if (!PowerCore || !LinkedInteractable) return;

	if (float CurrentPower = PowerCore->GetCurrentPowerLevel(); CurrentPower >= TargetPowerLevel)
	{
		LinkedInteractable->Activate();
	}
}

