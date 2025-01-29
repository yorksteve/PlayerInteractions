// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableBase.h"
#include "Terminal.generated.h"

UCLASS()
class PLAYERINTERACTIONS_API ATerminal : public AInteractableBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATerminal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Activate() override;

	virtual void OnInteract(ACharacter* Interactor) override;

private:
	UPROPERTY(EditAnywhere)
	AInteractableBase* LinkedInteractable;

	UPROPERTY(EditAnywhere)
	bool bIsActive = false;
};
