// Fill out your copyright notice in the Description page of Project Settings.


#include "LiftableItem.h"

#include "GameFramework/Character.h"

// Sets default values
ALiftableItem::ALiftableItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ALiftableItem::OnInteract(ACharacter* Interactor)
{
	Super::OnInteract(Interactor);

	if (bIsHeld)
	{
		Drop(Interactor);
	}
	else
	{
		Pickup(Interactor);
	}
}

void ALiftableItem::Pickup(ACharacter* Interactor)
{
	bIsHeld = true;
	MeshComponent->SetSimulatePhysics(false);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	this->AttachToComponent(Interactor->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("HandSocket"));
	
	// AttachToComponent
}

void ALiftableItem::Drop(ACharacter* Interactor)
{
	MeshComponent->SetSimulatePhysics(true);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	this->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

	bIsHeld = false;
}

// Called when the game starts or when spawned
void ALiftableItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALiftableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

