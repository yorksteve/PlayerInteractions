// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyCard.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AKeyCard::AKeyCard()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AKeyCard::BeginPlay()
{
	Super::BeginPlay();
	
}

void AKeyCard::OnInteract(ACharacter* Interactor)
{
	Super::OnInteract(Interactor);

	if (PickupSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, PickupSound, GetActorLocation());
	}
	
	this->Destroy();
}

// Called every frame
void AKeyCard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

