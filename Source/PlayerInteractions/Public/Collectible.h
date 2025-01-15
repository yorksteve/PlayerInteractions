// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Collectible.generated.h"

UCLASS()
class PLAYERINTERACTIONS_API ACollectible : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACollectible();

	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, Category="Components")
	USphereComponent* CollisionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio")
	USoundBase* CollectibleSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	FString ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	int32 Amount = 1;

protected:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

private:
	void OnItemPickedUp();
};
