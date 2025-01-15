// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerGenerator.generated.h"

UCLASS()
class PLAYERINTERACTIONS_API APowerGenerator : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APowerGenerator();

	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* MeshComponent;

	UFUNCTION(BlueprintCallable, Category="Power")
	float GetPowerChangeAmount() const;

	UPROPERTY(EditAnywhere, Category="Power")
	float PowerChangeAmount;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
