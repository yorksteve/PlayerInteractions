// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Elevator.h"
#include "Blueprint/UserWidget.h"
#include "ElevatorControlUI.generated.h"

UCLASS()
class PLAYERINTERACTIONS_API UElevatorControlUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Elevator")
	void SetElevatorReference(AElevator* NewElevator);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Elevator")
	AElevator* Elevator;
};
