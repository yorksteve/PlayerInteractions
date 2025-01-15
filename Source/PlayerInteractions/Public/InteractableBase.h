// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Actor.h"
#include "InteractableBase.generated.h"

UCLASS()
class PLAYERINTERACTIONS_API AInteractableBase : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInteractableBase();

	UPROPERTY(EditAnywhere, Category="Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, Category="Components")
	USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, Category="UI")
	UWidgetComponent* IconWidget;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	virtual void OnInteract(ACharacter* Interactor) override;

	virtual void DisplayInteractIcon(bool bShowIcon) override;

	virtual void Activate() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
