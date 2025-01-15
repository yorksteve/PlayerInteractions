﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

class PLAYERINTERACTIONS_API IInteractable
{
	GENERATED_BODY()

public:
	virtual void OnInteract(ACharacter* Interactor) = 0;
	virtual void DisplayInteractIcon(bool bShowIcon) = 0;
	virtual void Activate() = 0;
};
