// LeaveMeAlone Game by Netologiya. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LMAHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeath)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LEAVEMEALONE_API ULMAHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	ULMAHealthComponent();

	UFUNCTION(BlueprintCallable)
	float GetHealth() const { return Health; }

	UFUNCTION(BlueprintCallable)
	bool IsDead() const;

	bool AddHealth(float NewHealth);
	bool IsHealthFull() const;
	
	FOnDeath OnDeath;
	FOnHealthChanged OnHealthChanged;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MaxHealth = 100.0f;
	
	virtual void BeginPlay() override;


private:
	float Health = 0.0f;

	UFUNCTION()
	void OnTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
};
