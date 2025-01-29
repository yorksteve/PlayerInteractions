// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupItem.h"
#include "KeyCard.generated.h"

UCLASS()
class PLAYERINTERACTIONS_API AKeyCard : public APickupItem
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AKeyCard();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnInteract(ACharacter* Interactor) override;
};