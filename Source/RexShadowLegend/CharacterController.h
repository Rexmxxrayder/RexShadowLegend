// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RexShadowLegendCharacter.h"
#include "CharacterController.generated.h"

/**
 * 
 */
UCLASS()
class REXSHADOWLEGEND_API ACharacterController : public ARexShadowLegendCharacter
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere)
	float Health = 50.f;
};
