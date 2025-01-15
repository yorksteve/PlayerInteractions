// Fill out your copyright notice in the Description page of Project Settings.

#include "Chest.h"

// Sets default values
AChest::AChest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ChestLidMesh = CreateDefaultSubobject<UStaticMeshComponent>("ChestLidMesh");
	ChestLidMesh->SetupAttachment(MeshComponent);

	OpenSpeed = 100.f;
	bIsOpen = false;
}

// Called when the game starts or when spawned
void AChest::BeginPlay()
{
	Super::BeginPlay();

	ChestClosedPosition = ChestLidMesh->GetRelativeLocation();
	ChestOpenPosition = ChestClosedPosition + FVector(0, -70.f, 0);
}

void AChest::OnInteract(ACharacter* Interactor)
{
	Super::OnInteract(Interactor);

	ToggleLid();
}

void AChest::OnChestOpen()
{
	if (bItemSpawned) return;

	FVector SpawnLocation = GetActorLocation() + SpawnOffset;
	FRotator SpawnRotation = FRotator::ZeroRotator;

	for (TSubclassOf<AActor> Item : StoredItems)
	{
		if (Item == nullptr) continue;

		AActor* SpawnedItem = GetWorld()->SpawnActor<AActor>(Item, SpawnLocation, SpawnRotation);
		if (SpawnedItem)
		{
			bItemSpawned = true;
			UStaticMeshComponent* ItemMesh = Cast<UStaticMeshComponent>(SpawnedItem->GetComponentByClass(UStaticMeshComponent::StaticClass()));

			if (ItemMesh)
			{
				ItemMesh->SetSimulatePhysics(true);
				FVector ForwardVector = GetActorRightVector();
				ForwardVector = FMath::VRandCone(ForwardVector, FMath::DegreesToRadians(90.f));

				float RandomMagnitude = FMath::RandRange(200.f, 300.f);
				FVector ImpulseValue = ForwardVector * RandomMagnitude;
				ItemMesh->AddImpulse(ImpulseValue, NAME_None, true);
			}
		}
	}
}

// Called every frame
void AChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector TargetPosition = bIsOpen ? ChestOpenPosition : ChestClosedPosition;
	FVector CurrentPostion = ChestLidMesh->GetRelativeLocation();
	FVector NewPosition = FMath::VInterpConstantTo(CurrentPostion, TargetPosition, DeltaTime, OpenSpeed);
	
	ChestLidMesh->SetRelativeLocation(NewPosition);

	if (bIsOpen && NewPosition.Equals(ChestOpenPosition, 1.f))
	{
		OnChestOpen();
	}
}

void AChest::ToggleLid()
{
	bIsOpen = !bIsOpen;
}

