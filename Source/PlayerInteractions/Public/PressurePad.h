// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableBase.h"
#include "GameFramework/Actor.h"
#include "PressurePad.generated.h"

UCLASS()
class PLAYERINTERACTIONS_API APressurePad : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APressurePad();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* PadMesh;

	UPROPERTY(EditAnywhere)
	AInteractableBase* LinkedInteractable;

	UPROPERTY(EditAnywhere)
	float PressedDepthThreshold;

	void CheckPressurePadStatus();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	bool bIsPadActive;
};
