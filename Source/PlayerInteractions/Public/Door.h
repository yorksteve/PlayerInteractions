// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableBase.h"
#include "Components/TimelineComponent.h"
#include "Door.generated.h"

UCLASS()
class PLAYERINTERACTIONS_API ADoor : public AInteractableBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LeftDoor;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* RightDoor;

	UPROPERTY(EditAnywhere)
	UCurveFloat* OpenCurve;
	
	FTimeline OpenTimeline;
	FVector LeftDoorInitialPosition;
	FVector RightDoorInitialPosition;

	bool bIsOpen = false;

	UFUNCTION()
	void ControlDoor(float Value);

	UFUNCTION()
	void OnOpenComplete();

	void LockDoor(bool bLocked);

	bool IsDoorLocked() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void OnInteract(ACharacter* Interactor) override;

	virtual void Activate() override;

private:
	UPROPERTY(EditInstanceOnly)
	bool bIsLocked;
};