// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DecalActor.h"
#include "WallPainting.generated.h"

UCLASS()
class REXSHADOWLEGEND_API AWallPainting : public ADecalActor
{
	GENERATED_BODY()
	public : 
	UPROPERTY(VisibleAnywhere)
	UMaterialInterface* Material = nullptr;
};
