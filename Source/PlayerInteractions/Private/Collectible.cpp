// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectible.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerInteractions/PlayerInteractionsCharacter.h"


// Sets default values
ACollectible::ACollectible()
{
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	SetRootComponent(MeshComponent);

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Component"));
	CollisionComponent->SetupAttachment(MeshComponent);
}

void ACollectible::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (OtherActor->IsA(APlayerInteractionsCharacter::StaticClass()))
	{
		OnItemPickedUp();	
	}
}

void ACollectible::OnItemPickedUp()
{	
	if (CollectibleSound || !ItemType.IsEmpty() || Amount > 0)
	{
		UGameplayStatics::PlaySoundAtLocation(this, CollectibleSound, GetActorLocation());
		UE_LOG(LogTemp, Warning, TEXT("Picked up: %s and applied the amount: %d"), *ItemType, Amount);
		Destroy();
		        
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Missing CollectibleSound or ItemType is empty: %s or applied amount < 0: %d"), *ItemType, Amount);
	}
}