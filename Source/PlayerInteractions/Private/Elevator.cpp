// Fill out your copyright notice in the Description page of Project Settings.


#include "Elevator.h"

#include "ElevatorControlUI.h"
#include "GameFramework/Character.h"


// Sets default values
AElevator::AElevator()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bIsPoweredOn = false;
	bIsMoving = false;
	MovementSpeed = 5.f;
	MovementProgress = 0.f;
}

// Called when the game starts or when spawned
void AElevator::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	EndLocation = FVector(StartLocation.X, StartLocation.Y, ElevatorFloors[CurrentFloorIndex]->GetActorLocation().Z);
}

// Called every frame
void AElevator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bIsMoving) return;

	MovementProgress += DeltaTime / MovementSpeed;
	SetActorLocation(FMath::Lerp(StartLocation, EndLocation, MovementProgress));

	if (MovementProgress >= 1.f)
	{
		bIsMoving = false;
		MovementProgress = 0.f;
	}
}

void AElevator::OnInteract(ACharacter* Interactor)
{
	if (!bIsPoweredOn) return;
	
	Super::OnInteract(Interactor);

	PlayerController = Cast<APlayerController>(Interactor->GetController());
	if (PlayerController && bIsPoweredOn && !bIsMoving)
	{
		if (!ElevatorUI)
		{
			ElevatorUI = CreateWidget<UUserWidget>(GetWorld(), ElevatorUIClass);
			if (ElevatorUI)
			{
				UElevatorControlUI* ElevatorControlUI = Cast<UElevatorControlUI>(ElevatorUI);
				if (ElevatorControlUI)
				{
					ElevatorControlUI->SetElevatorReference(this);
				}
			}

			ElevatorUI->AddToViewport();
		}

		ShowElevatorUI(true);
		SetCursorVisibility(true);

		IconWidget->SetVisibility(false);
	}
}

void AElevator::Activate()
{
	Super::Activate();

	bIsPoweredOn = true;
}

void AElevator::MoveToFloor(int FloorIndex)
{
	ShowElevatorUI(false);
	SetCursorVisibility(false);

	if (bIsMoving || !ElevatorFloors.IsValidIndex(FloorIndex)) return;
	
	StartLocation = GetActorLocation();
	EndLocation = FVector(StartLocation.X, StartLocation.Y, ElevatorFloors[FloorIndex]->GetActorLocation().Z);
	MovementProgress = 0.f;
	bIsMoving = true;

	IconWidget->SetVisibility(true);
}

void AElevator::ShowElevatorUI(bool bShowElevatorUI)
{
	if (ElevatorUI)
	{
		ElevatorUI->SetVisibility(bShowElevatorUI ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
	}
}

void AElevator::SetCursorVisibility(bool bIsCursorVisible)
{
	if (PlayerController)
	{
		PlayerController->bShowMouseCursor = bIsCursorVisible;
	}
}