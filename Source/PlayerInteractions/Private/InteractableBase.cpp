#include "InteractableBase.h"
#include "Components/WidgetComponent.h"

// Sets default values
AInteractableBase::AInteractableBase()
{
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	SetRootComponent(MeshComponent);

	CollisionComponent = CreateDefaultSubobject<USphereComponent>("Collision Component");
	CollisionComponent->SetupAttachment(MeshComponent);

	IconWidget = CreateDefaultSubobject<UWidgetComponent>("IconWidget");
	IconWidget->SetupAttachment(RootComponent);
	IconWidget->SetWidgetSpace(EWidgetSpace::Screen);
	IconWidget->SetVisibility(false);
}

void AInteractableBase::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	DisplayInteractIcon(true);
}

void AInteractableBase::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	DisplayInteractIcon(false);
}

void AInteractableBase::OnInteract(ACharacter* Interactor)
{
}

void AInteractableBase::DisplayInteractIcon(bool bShowIcon)
{
	IconWidget->SetVisibility(bShowIcon);
}

void AInteractableBase::Activate()
{
}

// Called when the game starts or when spawned
void AInteractableBase::BeginPlay()
{
	Super::BeginPlay();
	IconWidget->SetVisibility(false);
}

