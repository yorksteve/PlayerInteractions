// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableBase.h"
#include "PickupItem.generated.h"

UCLASS()
class PLAYERINTERACTIONS_API APickupItem : public AInteractableBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APickupItem();

	UPROPERTY(EditAnywhere, Category="Audio")
	USoundBase* PickupSound;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnInteract(ACharacter* Interactor) override;
	virtual void Activate() override;
};
