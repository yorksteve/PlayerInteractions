// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableBase.h"
#include "Chest.generated.h"

UCLASS()
class PLAYERINTERACTIONS_API AChest : public AInteractableBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AChest();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ChestLidMesh;

	UPROPERTY(EditInstanceOnly, Category="Items")
	TArray<TSubclassOf<AActor>> StoredItems;

	UPROPERTY(EditInstanceOnly, Category="Items")
	FVector SpawnOffset;

	UPROPERTY(EditAnywhere, Category="Animation")
	float OpenSpeed;

	void ToggleLid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnInteract(ACharacter* Interactor) override;

	void OnChestOpen();

private:
	bool bIsOpen = false;
	bool bItemSpawned = false;
	
    FVector ChestClosedPosition;
    FVector ChestOpenPosition;
};