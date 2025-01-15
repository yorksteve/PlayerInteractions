// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerCore.h"
#include "PowerGenerator.h"
#include "PowerReceiver.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
APowerCore::APowerCore()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

float APowerCore::GetCurrentPowerLevel()
{
	return CurrentPowerLevel;
}

// Called when the game starts or when spawned
void APowerCore::BeginPlay()
{
	Super::BeginPlay();

	DynamicMaterial = MeshComponent->CreateAndSetMaterialInstanceDynamic(0);
	MeshComponent->SetMaterial(0, DynamicMaterial);
}

void APowerCore::ModifyPowerLevel(float PowerToAdd)
{
	if (bPoweredUp) return;
	
	CurrentPowerLevel += PowerToAdd;
	UpdateMaterialEmissiveProperties();
	if (CurrentPowerLevel == TargetPowerLevel) bPoweredUp = true;
	UE_LOG(LogTemp, Warning, TEXT("Current power level: %f"), CurrentPowerLevel);
}

// Called every frame
void APowerCore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APowerCore::Drop(ACharacter* Interactor)
{
	Super::Drop(Interactor);
	
	FVector Location = GetActorLocation();

	if (const UWorld* World = GetWorld())
	{
		float DetectionRadius = 100.f;
		TArray<AActor*> FoundActors;
		UKismetSystemLibrary::SphereOverlapActors(
			World,
			Location,
			DetectionRadius,
			TArray<TEnumAsByte<EObjectTypeQuery>>(),
			APowerGenerator::StaticClass(),
			TArray<AActor*>(),
			FoundActors);

		for (AActor* Actor : FoundActors)
		{
			const APowerGenerator* PowerGenerator = Cast<APowerGenerator>(Actor);
			if (!PowerGenerator) continue;

			const float PowerToAdd = PowerGenerator->GetPowerChangeAmount();
			ModifyPowerLevel(PowerToAdd);

			if (PowerGenerator->MeshComponent->DoesSocketExist(TEXT("PowerCoreSocket")))
			{
				MeshComponent->SetSimulatePhysics(false);
				AttachToComponent(PowerGenerator->MeshComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("PowerCoreSocket"));

				if (APowerReceiver* PowerReceiver = Cast<APowerReceiver>(Actor))
				{
					PowerReceiver->OnPowerCoreDropped(this);
				}
			}

			break;
		}
	}
}

void APowerCore::UpdateMaterialEmissiveProperties()
{
	if (!DynamicMaterial) return;
	
	if (CurrentPowerLevel <= TargetPowerLevel)
	{
		float EmissiveIntensity = FMath::Clamp(CurrentPowerLevel / TargetPowerLevel, 0.0f, 1.0f);
		DynamicMaterial->SetScalarParameterValue(TEXT("EmissivePower"), EmissiveIntensity);

		FLinearColor ColorShift = FLinearColor::LerpUsingHSV(FLinearColor::Red, FLinearColor::Green, EmissiveIntensity);
		DynamicMaterial->SetVectorParameterValue(TEXT("EmissiveColor"), ColorShift);
	}
	else
	{
		DynamicMaterial->SetVectorParameterValue(TEXT("EmissiveColor"), FLinearColor::Red);
	}
}