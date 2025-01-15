// Fill out your copyright notice in the Description page of Project Settings.


#include "Terminal.h"


// Sets default values
ATerminal::ATerminal()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATerminal::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATerminal::Activate()
{
	UE_LOG(LogTemp, Warning, TEXT("ATerminal::Activate"));
	bIsActive = true;
}

void ATerminal::OnInteract(ACharacter* Interactor)
{
	Super::OnInteract(Interactor);

	if (!bIsActive) return;

	if (LinkedInteractable)
	{
		LinkedInteractable->Activate();
	}
}