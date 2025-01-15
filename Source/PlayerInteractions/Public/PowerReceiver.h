// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableBase.h"
#include "PowerGenerator.h"
#include "PowerReceiver.generated.h"

class APowerCore;

UCLASS()
class PLAYERINTERACTIONS_API APowerReceiver : public APowerGenerator
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APowerReceiver();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnPowerCoreDropped(APowerCore* PowerCore);

	UPROPERTY(EditAnywhere, Category="Power")
	float TargetPowerLevel;

	UPROPERTY(EditAnywhere, Category="LinkedInteractable")
	AInteractableBase* LinkedInteractable;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	
};
