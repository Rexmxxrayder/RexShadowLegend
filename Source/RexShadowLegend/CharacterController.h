#pragma once

#include "CoreMinimal.h"
#include "RexShadowLegendCharacter.h"
#include "CharacterController.generated.h"

UCLASS()
class REXSHADOWLEGEND_API ACharacterController : public ARexShadowLegendCharacter
{
    GENERATED_BODY()
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	UFUNCTION()
	void ChangeHealth(float amount);
	UFUNCTION()
	void Respawn();
	UFUNCTION()
	void Die();
	UFUNCTION()
	void Launch();
	UPROPERTY(EditAnywhere)
	float Health = 50.f;
	UPROPERTY()
	float CurrentHealth = 50.f;
	UPROPERTY(EditAnywhere)
	float ReviveTime = 2.f;
	UPROPERTY(EditAnywhere)
	AActor* SpawnPoint = nullptr;
	UPROPERTY(EditAnywhere)
	float DistProjectile = 10;
};
