// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableBase.h"
#include "LiftableItem.generated.h"

UCLASS()
class PLAYERINTERACTIONS_API ALiftableItem : public AInteractableBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALiftableItem();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnInteract(ACharacter* Interactor) override;

	virtual void Pickup(ACharacter* Interactor);

	virtual void Drop(ACharacter* Interactor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	bool bIsHeld;
};
