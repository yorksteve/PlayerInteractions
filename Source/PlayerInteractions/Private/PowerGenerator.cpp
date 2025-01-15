// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerGenerator.h"


// Sets default values
APowerGenerator::APowerGenerator()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	SetRootComponent(MeshComponent);
	PowerChangeAmount = 10.f;
}

// Called when the game starts or when spawned
void APowerGenerator::BeginPlay()
{
	Super::BeginPlay();
}

float APowerGenerator::GetPowerChangeAmount() const
{
	return PowerChangeAmount;
}

