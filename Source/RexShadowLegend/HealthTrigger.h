// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterController.h"
#include "Components/PointLightComponent.h"
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthTrigger.generated.h"

UCLASS()
class REXSHADOWLEGEND_API AHealthTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealthTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void TimerUpdate(float DeltaTime);
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere)
	UBoxComponent* Collider = nullptr;
	UPROPERTY(EditAnywhere)
	UPointLightComponent* Light = nullptr;
	UPROPERTY(EditAnywhere)
	float Amount = 10.f;
	UPROPERTY(EditAnywhere)
	float Timer = 2.f;
	UPROPERTY()
	float CurrentTimer = 0.f;
	UPROPERTY()
	ACharacterController* CharacterInside = nullptr;
};
