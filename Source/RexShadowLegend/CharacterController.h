#pragma once

#include "CoreMinimal.h"
#include <string>
#include <iostream>
#include "RexShadowLegendCharacter.h"
#include "MySaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "CharacterController.generated.h"

UCLASS()
class REXSHADOWLEGEND_API ACharacterController : public ARexShadowLegendCharacter
{
    GENERATED_BODY()
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION(BlueprintCallable, category = "Functionnnnn")
	void SaveGame(FString name);
	UFUNCTION(BlueprintCallable, category = "Functionnnnn")
	void LoadGame(FString name);
	UFUNCTION()
	void ChangeHealth(float amount, bool setTo = false);
	UFUNCTION()
	void Respawn();
	UFUNCTION()
	void Die();
	UFUNCTION()
	void Launch();
	UPROPERTY(EditAnywhere)
	float Health = 50.f;
	UPROPERTY(BlueprintReadWrite)
	float CurrentHealth = 50.f;
	UPROPERTY(EditAnywhere)
	float ReviveTime = 2.f;
	UPROPERTY(EditAnywhere)
	AActor* SpawnPoint = nullptr;
	UPROPERTY(EditAnywhere)
	float DistProjectile = 10;
};
