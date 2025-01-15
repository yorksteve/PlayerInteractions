// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableBase.h"
#include "LightInteractable.generated.h"

UCLASS()
class PLAYERINTERACTIONS_API ALightInteractable : public AInteractableBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALightInteractable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnInteract(ACharacter* Interactor) override;
	virtual void Activate() override;

private:
	UPROPERTY(EditDefaultsOnly, Category="Light")
	UMaterialInstanceDynamic* DynamicMaterial;

	UPROPERTY(EditAnywhere, Category="Light")
	bool bIsOn = false;

	UPROPERTY(EditAnywhere, Category="Light")
	float MaxIntensity = 5.f;

	UPROPERTY(EditAnywhere, Category="Light")
	float MinIntensity = 0.f;

	float CurrentIntensity;

	void SetLightIntensity();
};
