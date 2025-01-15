// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

#include "InventoryManager.h"

// Sets default values
ADoor::ADoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LeftDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left Door"));
	RightDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right Door"));

	LeftDoor->AttachToComponent(MeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
	RightDoor->AttachToComponent(MeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	FOnTimelineFloat ProgressFunction;
	ProgressFunction.BindUFunction(this, FName("ControlDoor"));

	FOnTimelineEventStatic OnFinishCallback;
	OnFinishCallback.BindUFunction(this, FName("OnOpenComplete"));

	OpenTimeline.AddInterpFloat(OpenCurve, ProgressFunction);
	OpenTimeline.SetTimelineFinishedFunc(OnFinishCallback);

	LeftDoorInitialPosition = LeftDoor->GetRelativeLocation();
	RightDoorInitialPosition = RightDoor->GetRelativeLocation();

	OpenTimeline.SetLooping(false);
}

void ADoor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	OpenTimeline.TickTimeline(DeltaSeconds);
}

void ADoor::OnInteract(ACharacter* Interactor)
{
	Super::OnInteract(Interactor);

	if (bIsLocked)
	{
		UInventoryManager* InventoryManager = UInventoryManager::GetInstance();
		if (!InventoryManager || !InventoryManager->HasItem(TEXT("BP_Card_C_0")))
		{
			return;
		}

		LockDoor(false);
	}

	if (OpenTimeline.IsPlaying())
	{
		return;
	}

	if (!bIsOpen && !OpenTimeline.IsReversing())
	{
		OpenTimeline.PlayFromStart();
	}
	else
	{
		OpenTimeline.ReverseFromEnd();
	}
}

void ADoor::Activate()
{
	Super::Activate();
	LockDoor(false);
}

void ADoor::ControlDoor(float Value)
 {
	FVector NewLeftDoorPosition = LeftDoorInitialPosition + FVector(-Value, 0, 0);
	FVector NewRightDoorPosition = RightDoorInitialPosition + FVector(Value, 0, 0);

	LeftDoor->SetRelativeLocation(NewLeftDoorPosition);
	RightDoor->SetRelativeLocation(NewRightDoorPosition);
 }
 
 void ADoor::OnOpenComplete()
 {
	bIsOpen = !bIsOpen;
 }

void ADoor::LockDoor(bool bLocked)
{
	bIsLocked = bLocked;
}

bool ADoor::IsDoorLocked() const
{
	return bIsLocked;
}