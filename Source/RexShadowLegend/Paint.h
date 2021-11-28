// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Paint.generated.h"

UCLASS()
class REXSHADOWLEGEND_API APaint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APaint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
