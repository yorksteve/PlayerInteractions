// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableBase.h"
#include "Elevator.generated.h"

UCLASS()
class PLAYERINTERACTIONS_API AElevator : public AInteractableBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AElevator();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnInteract(ACharacter* Interactor) override;

	virtual void Activate() override;

	UPROPERTY(VisibleAnywhere, Category="Movement")
	bool bIsMoving;

	UPROPERTY(EditAnywhere, Category="Movement")
	bool bIsPoweredOn;

	UPROPERTY(EditAnywhere, Category="Movement")
	float MovementSpeed;

	UPROPERTY(EditAnywhere, Category="Movement")
	TArray<AActor*> ElevatorFloors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UI")
	TSubclassOf<UUserWidget> ElevatorUIClass;

	UPROPERTY()
	UUserWidget* ElevatorUI = nullptr;

	UPROPERTY()
	APlayerController* PlayerController;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FVector StartLocation;
	FVector EndLocation;

	float MovementProgress;

	UFUNCTION(BlueprintCallable)
	void MoveToFloor(int FloorIndex);

	int CurrentFloorIndex = 0;

	void ShowElevatorUI(bool bShowElevatorUI);

	void SetCursorVisibility(bool bIsCursorVisible);
};
