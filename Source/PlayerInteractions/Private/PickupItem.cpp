// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupItem.h"

#include "InventoryManager.h"
#include "MainGameInstance.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
APickupItem::APickupItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APickupItem::BeginPlay()
{
	Super::BeginPlay();
}

void APickupItem::OnInteract(ACharacter* Interactor)
{
	Super::OnInteract(Interactor);

	if (const UMainGameInstance* MainGameInstance = Cast<UMainGameInstance>(GetWorld()->GetGameInstance()))
	{
		MainGameInstance->InventoryManager->AddItem(this);
		if (PickupSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, PickupSound, GetActorLocation());
		}
		Destroy();
	}
}

void APickupItem::Activate()
{
}