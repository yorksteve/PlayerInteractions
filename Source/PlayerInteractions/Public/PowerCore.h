// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LiftableItem.h"
#include "PowerCore.generated.h"

UCLASS()
class PLAYERINTERACTIONS_API APowerCore : public ALiftableItem
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APowerCore();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Drop(ACharacter* Interactor) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Power Level")
	float TargetPowerLevel = 100.f;

	UFUNCTION(BlueprintCallable)
	float GetCurrentPowerLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void ModifyPowerLevel(float PowerToAdd);

	float CurrentPowerLevel = 0.0f;

	UFUNCTION(BlueprintCallable)
	void UpdateMaterialEmissiveProperties();

	UPROPERTY(EditDefaultsOnly)
	UMaterialInstanceDynamic* DynamicMaterial;

	bool bPoweredUp = false;
};
