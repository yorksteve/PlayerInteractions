// Fill out your copyright notice in the Description page of Project Settings.


#include "PressurePad.h"


// Sets default values
APressurePad::APressurePad()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	SetRootComponent(BaseMesh);

	PadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pad Mesh"));
	PadMesh->SetupAttachment(BaseMesh);

	PressedDepthThreshold = 0.f;

	bIsPadActive = false;
}

// Called when the game starts or when spawned
void APressurePad::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APressurePad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsPadActive) return;

	CheckPressurePadStatus();
}

void APressurePad::CheckPressurePadStatus()
{
	FVector PadLocation = PadMesh->GetComponentLocation();
	float PadDepth = PadLocation.Z - BaseMesh->GetComponentLocation().Z;

	if (PadDepth <= PressedDepthThreshold)
	{
		UE_LOG(LogTemp, Warning, TEXT("Pressure Pad activated"))

		if (LinkedInteractable)
		{
			LinkedInteractable->Activate();
			bIsPadActive = true;
		}
	}
}