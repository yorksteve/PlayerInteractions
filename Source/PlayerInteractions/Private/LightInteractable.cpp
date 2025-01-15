// Fill out your copyright notice in the Description page of Project Settings.


#include "LightInteractable.h"


// Sets default values
ALightInteractable::ALightInteractable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrentIntensity = 0.f;
	bIsOn = false;
}

// Called when the game starts or when spawned
void ALightInteractable::BeginPlay()
{
	Super::BeginPlay();

	DynamicMaterial = MeshComponent->CreateAndSetMaterialInstanceDynamic(1);

	SetLightIntensity();
}

void ALightInteractable::OnInteract(ACharacter* Interactor)
{
	Super::OnInteract(Interactor);

	bIsOn = !bIsOn;
	SetLightIntensity();
}

void ALightInteractable::Activate()
{
}

void ALightInteractable::SetLightIntensity()
{
	CurrentIntensity = bIsOn ? MaxIntensity : MinIntensity;
	
	DynamicMaterial->SetScalarParameterValue(TEXT("EmissivePower"), CurrentIntensity);
}
